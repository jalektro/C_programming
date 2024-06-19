/*
Exercise 5: String Duplication
Task: Write a function char *strdup(const char *str) that duplicates a given string using malloc. 
Ensure to free the memory allocated for the duplicate string in the main function.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strdup (const char *str)
{
	if (str == NULL)
		return NULL;
	
	char *dup = (char *) malloc(strlen(str)+1);
	if (dup ==NULL)
	{
		printf("allocation failed");
		return NULL;
	}
	
	strcpy(dup ,str);
	return dup;
}

int main(void)
{
	const char *original ="This is the original sentence";
	
	char *copy = strdup(original);
	
	if(copy != NULL)
	{
		printf("original sentence is : %s\n", original);
		printf("duplicate is : %s\n", copy);
		
		free(copy);
	} else	{
		printf("memory allocation failed\n");
	}
	
	
	return 0;
}