//trying to understand how the trim function workds (9/9/2019)
//start: https://stackoverflow.com/questions/122616/how-do-i-trim-leading-trailing-whitespace-in-a-standard-way
#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> //isspace 
#include <string.h> 

char *trimLine(char* str){ // testing this function! 
	char *end; 
	while(isspace(*str)) ++str; //removes leading space 
	
	if(*str == 0) // all spaces? 
		return str; 

	printf("working\n");
	//trim trailing space 
	end = str + strlen(str) - 1; 
	while(end > str && isspace((unsigned char)*end)){
		end--; 
	}

	//write new null terminator character 
	end[1] = '\0'; 

	return str; 
}

int main(){ //should print "remove the spaces"
	char *line = "     remove the spaces     "; 
	char *lineDone = trimLine(line); 

	printf("%s\n", line);
	printf("%s\n", lineDone);

	return 0; 
}