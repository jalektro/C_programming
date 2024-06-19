/*
Exercise 4: Memory Leak Detection
Task: Write a program that allocates memory dynamically using malloc but deliberately forgets to free it. 
Use a memory leak detection tool (like Valgrind) to identify the memory leak.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    // Allocate memory for an array of 10 integers using malloc
    int *arr = (int *)malloc(10 * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Populate the array with values
    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1;
    }

    // Print the values
    printf("Array values:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Deliberately forget to free the allocated memory
    // free(arr);
	
	return 0;
}
