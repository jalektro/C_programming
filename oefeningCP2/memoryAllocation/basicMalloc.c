/*
Exercise 1: Basic Dynamic Memory Allocation
Task: Write a program that allocates memory for an array of 10 integers using malloc. 
Initialize the array with values 1 to 10, then print the values and free the memory.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	
	int *arr = (int *) malloc (10*sizeof( int));
	if (arr == NULL)
	{
		printf("memory allocation failed\n");
		return 1;
	}
	for (int i= 0; i<10; i++){
	arr[i] = i+1;
	printf("%d,	", arr[i]);
	}
	
	free (arr);
	arr = NULL;
	
	return 0;
}