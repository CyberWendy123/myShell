/*
a simple program to understand how to split a string
sometimes it is easier to break things into smaller parts to understand 
*/ 
#include <stdio.h> 
#include <string.h> 

int main(int argc, char *argv[]){
	char str[] = "let us split this string"; //should give us an array of size 5 
	char* delim = " "; //splitting it by space 
	char* words[10]; 
	int i = 0; 

	//this is the code to do what i wnat to do but... 
	char* token = strtok(str, delim); 
	while(token != NULL){
		words[i] = token; 
		//printf("%s\n", words[i]);
		token = strtok(NULL, delim); 
		i++; 
	}

	//...I need it to be *str not str[]- how do I do that? 
	char* str2 , *toFree, *token2; 
	char* words2[10]; 
	toFree = str2 = strdup("one"); 
	i = 0; 

	while((token2 = strsep(&str2, delim))!= NULL){
		words2[i] = token2; 
		printf("%s\n", words2[i]);
		i++ ; 
	} //basically, instead of strok(), use strsep()  


	return 0; 
}