#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> //the boolean library 
#include <string.h> 

void trimLine(char* line)
{ 	//remove leading/trailing whitespace 
}

int main(int argc, char *argv[])
{
	int byte_size = 250; 
	char *command = malloc(byte_size * sizeof(char)); 
	char *quit = "q"; 

	do{
		printf("$: ");
		scanf("%s", command); 
		
		command[strlen(command) - 1] = 0; //remove \n at the end
		trimLine(command); //remove leading/trailing whitespace 

		//if q, quit program 
		if(strcmp(command, quit))
			break; 
	} while(1); 

	free(command); 
	return 0; 
}