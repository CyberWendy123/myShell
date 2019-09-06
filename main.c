#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> //the boolean library 
#include <ctype.h> //isspace function 
#include <string.h> 

char* trimLine(char* str) //remove leading/trailing whitespace 
{ 	//tried to find code without memory leaks 
	char *end; 
	while(isspace((unsigned char)*str)) str++; //trim leading 
	end = str + strlen(str) - 1; 
	while(end> str && isspace((unsigned char)* end)) end--; 
	*(end + 1) = '\0'; 
	return (str); 
}

int main(int argc, char *argv[])
{
	int byte_size = 250; 
	char *enteredValue = malloc(byte_size * sizeof(char)); 
	char *command; //cleaned up version 
	char *quit = "quit()"; 

	do{ // a do while loop 
		printf("$: ");
		scanf("%s", enteredValue); 
		
		enteredValue[strlen(enteredValue) - 1] = '\0'; //remove \n at the end
		command = trimLine(enteredValue); //remove leading/trailing whitespace 

		//if q, quit program 
		if(strcmp(command, quit))
			break; 
	} while(1); 

	free(enteredValue); 
	return 0; 
}