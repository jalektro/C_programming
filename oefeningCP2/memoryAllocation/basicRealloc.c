/*
Exercise 3: Reallocating Memory
Task: Write a program that allocates memory for an array of 5 integers using malloc. 
Populate the array with values, then use realloc to resize the array to hold 10 integers.
 Initialize the new elements and print all values. Free the memory.
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 
 int main (void)
 {
	 printf("compiler works");
	 
	int *arr = (int *) malloc (5* sizeof(int));
	if(arr == NULL)
	{
		printf("allocation failed\n");
		return 1;
	}
	
	for (int i = 0; i<5; i++){
		arr[i]= i+1;
	}
	
	printf("initial values\n");
	for (int i = 0; i<5; i++){
		printf("value %d = %d\n", i, arr[i]);
	}
	
	arr = (int *) realloc(arr, 10*sizeof(int));
	if(arr == NULL){
		printf("reallac failed\n");
		return 1;
	}
	
	for (int i = 5; i<10; i++){
		arr[i]= i+1;
	}
	
	printf("values after realloc\n");
	for (int i = 0; i<10; i++){
		printf("value %d = %d\n", i, arr[i]);
	}
	
	free(arr);
	 return 0;
 }
 