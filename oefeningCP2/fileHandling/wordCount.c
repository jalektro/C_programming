/*
### Exercise 3: File Word Count

Write a program that reads a text file (`textfile.txt`) and counts the number of words in it.
 Words are separated by spaces, tabs, or newline characters.
*/

#include <stdio.h>
#include <ctype.h>

int isWordSeperator(char c){
return c == ' ' || c == '\t' || c ==  '\n';
}

int main(void)
{
	char c;
	int inWord= 0;
	int wordCount =0;
	FILE *filePtr = fopen("input.txt", "r");
	if(filePtr == NULL){
		printf("failed to open file");
		return 0;
	}
	
	while((c = fgetc(filePtr)) != EOF){
		if(isWordSeperator(c)){
			if (inWord) {
			inWord = 0;
			wordCount++;
			}
		} else{ 
		inWord =1;
			}	
		}
		
		if(inWord)	{
			wordCount++;
		}
	fclose(filePtr);
	
	printf("The file contains %d words.\n",wordCount);
		
	return 0;
}