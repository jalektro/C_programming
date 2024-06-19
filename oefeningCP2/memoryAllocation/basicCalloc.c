/*
Exercise 2: Using calloc
Task: Write a program that allocates memory for an array of 10 integers using calloc. 
Verify that the memory is initialized to zero, then assign and print values, and finally free the memory.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	
	int *arr = (int *) calloc(10,sizeof( int));
	if (arr == NULL)
	{
		printf("memory allocation failed\n");
		return 1;
	}
	for (int i= 0; i<10; i++){
	
	printf("%d,	", arr[i]);
	}
	
	for (int i= 0; i<10; i++){
	arr[i] = i+1;
	printf("%d,	", arr[i]);
	}
	
	free (arr);
	arr = NULL;
	
	return 0;
}