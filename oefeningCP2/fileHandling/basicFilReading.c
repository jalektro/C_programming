/*
Exercise 1: Basic File Reading and Output
Write a program that reads content from a text file (input.txt) and outputs it to the console.
*/

#include <stdio.h>

int main(void){
	char buffer[1024];
	FILE *filePtr = fopen("input.txt","r");
	if (filePtr == NULL){
		printf("failed to open file\n");
		return 1;
	}	
	
	while(fgets(buffer, sizeof(buffer), filePtr) != NULL){	
	printf("%s",buffer);
	}
	
	fclose(filePtr);
	
	return 0;
}