/*
* To do list 
	-	addToHistory function - gotta do fix size
	-	implement background process via & 
	-	implement fork via exec() 
*/ 
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> //the boolean library 
#include <ctype.h> //isspace function 
#include <string.h> 
#include <unistd.h> 
#include <sys/wait.h>
#include <sys/types.h> 

char* trimLine(char* str) //remove leading/trailing whitespace 
{ 	//tried to find code without memory leaks 
	char* end; 
	while(isspace((unsigned char)*str)) str++; //trim leading 
	end = str + strlen(str) - 1; 
	while(end> str && isspace((unsigned char)* end)) end--; 
	*(end + 1) = '\0'; 
	return (str); 
}

void addToHistory(char* fileName, char* str) 
{
	int maxLine = 50; 
	char* strInsert = malloc(sizeof(char) * 250); 	
	strcpy(strInsert, str); 
	strcat(strInsert, "\n"); //adding "enter" for the file 

	//open history file 
	FILE *fp = fopen(fileName, "a"); 
	if(fp == NULL){
		puts("Couldn't open file"); 
		exit(0); 
	}
	else {
		fputs(strInsert, fp); 
		fclose(fp); 
	}
	free(strInsert); 
}

void displayHistory(char* fileName){
	//open history file 
	FILE * fp = fopen(fileName, "r"); 
	char buff[255]; 
	int count = 1; 

	if(fp){
		while(fgets(buff, 255, fp) != NULL){ //read a line 
			printf("%d \t %s", count, buff); 
			count++; 
		}
	}
	fclose(fp); 
}

int main(int argc, char *argv[])
{
	int byte_size = 250; 
	char* enteredValue = malloc(byte_size * sizeof(char)); 
	char* command; //cleaned up version 
	char* quit = "quit()"; 
	char* showHistory = "history"; //display history command 
	char* fileName = "historyShell.txt"; 
	int pid; 

	do{ // a do while loop 
		printf("$: ");
		scanf("%s", enteredValue); 
		
		if(enteredValue[strlen(enteredValue)] == '\n')
			enteredValue[strlen(enteredValue)] = '\0'; //remove \n at the end
		command = trimLine(enteredValue); //remove leading/trailing whitespace 

		addToHistory(fileName, command); 

		//if history, print out the file 
		if(strcmp(command, showHistory) == 0)
			displayHistory(fileName); 
		//if quit(), quit program 
		else if(strcmp(command, quit) == 0)
			break; 

		pid = fork(); //and it goes into two different directions...
		if(pid == 0){ //child 
			execvp(command, args); //fix here <--
			perror("exec"); 
			exit(1); 
		}
		else{ //parents 
			wait(NULL); 
		}

	} while(1); 

	free(enteredValue); 
	return 0; 
}