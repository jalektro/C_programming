/*
### Exercise 4: File Line Count

Write a program that reads a text file (`data.txt`) and counts the number of lines in it.
 Each line ends with a newline character (`'\n'`).
*/

#include <stdio.h>


int main(void)
{
	char c;
	int lineCount =0;
	FILE *filePtr = fopen("input.txt", "r");
	if(filePtr == NULL){
		printf("failed to open file");
		return 0;
	}
	
	while((c = fgetc(filePtr)) != EOF){
		if(c == '\n'){
			lineCount++;
			}
		} 

	fclose(filePtr);
	
	printf("The file contains %d lines.\n",lineCount);
		
	return 0;
}