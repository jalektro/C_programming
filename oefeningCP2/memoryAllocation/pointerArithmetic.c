/*
Exercise 10: Pointer Arithmetic
Task: Write a program that allocates memory for an array of 10 integers using malloc.
 Use pointer arithmetic to set and print the values of the array. Free the memory afterward.
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 
 int main(void)	{
	 
	int *array = (int *) malloc(10 * sizeof(int));
	 if (array == NULL){
		 printf("Allocation failed.");
		 return 1;
	 }
	 
	 for(int i = 0; i<10;i++){			
		 *(array+i) = i+1;
	 }	 
/*
The program uses a for loop to set the values of the array using pointer arithmetic.
The expression *(array + i) is used to access the i-th element of the array and set its value to i + 1.
*/	 
	 printf("The values are: \n");
	 for(int i = 0; i<10; i++){
		 printf("%d	", *(array+i));
	 }
	  printf("\n");
	 
	 free(array);
	 return 0;
 }