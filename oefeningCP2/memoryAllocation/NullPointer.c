/*
Exercise 9: Handling NULL Pointers
Task: Write a program that attempts to allocate a large amount of memory (e.g., 1 GB). 
Check if malloc returns NULL and handle the error gracefully.
*/

#include <stdio.h>
#include <stdlib.h>


int main(void) {
	
	size_t size = 1* 1024 * 1024 *1024; // 1GB in Bytes
	void *largeMemory = malloc(size);
	
	if (largeMemory == NULL) {
		       // Handle the error gracefully
        printf("Memory allocation failed. Unable to allocate %zu bytes.\n", size);
    } else {
        // If allocation is successful, do something with the memory
        printf("Memory allocation succeeded. Allocated %zu bytes.\n", size);

        // Simulate usage of allocated memory
        // For demonstration, we will just write a value to the first byte
        *((char *)largeMemory) = 'A';

        // Free the allocated memory
        free(largeMemory);
    }
	
	return 0;
}