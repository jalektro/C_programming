/*
### Exercise 2: File Copy

Write a program that copies the contents of one file (`source.txt`) to another file (`destination.txt`). 
Make sure to handle errors if the source file does not exist or if there are issues with opening or writing to the destination file.
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc<2){
		printf("no arguments are given\n");
		return 1;
	}
	
	char *mainFile = argv[1];
	
	FILE *sourceFile = fopen(mainFile, "r");
	if (sourceFile == NULL){
		printf("Failed to open the sourceFile;\n");
		return 1;
	}
	
	FILE *destinationFile = fopen("destination.txt", "w");
	if(destinationFile == NULL){
		printf("Failed to open destinationFile.\n");
		return 1;
	}
	
	char buffer[1024];
	size_t bytesRead;
	
	while ((bytesRead = fread(buffer,1,1024,sourceFile)) > 0)
	{
		fwrite(buffer,1,bytesRead,destinationFile);
	}
	
	fclose(sourceFile);
	fclose(destinationFile);
	
	printf("No error occured so copy is finished.\n");
	
	return 0;
}