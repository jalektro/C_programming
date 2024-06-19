/*
6. **Concatenating Rows:**
   Create a program that concatenates all rows of integers passed as command line arguments (`argv`) into a single array.
   Print the concatenated array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if argc is at least 2 (since argv[0] is the program name)
    if (argc < 2) {
        printf("Usage: %s <row1> <row2> ... <rowN>\n", argv[0]);
        return 1;
    }

    // Calculate total length of concatenated array
    int total_length = 0;
    for (int i = 1; i < argc; i++) {
        total_length += strlen(argv[i]) + 1; // +1 for space separator or '\0'
    }

    // Allocate memory for the concatenated array
    char *concatenated = (char *)malloc(total_length * sizeof(char));
    if (concatenated == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Concatenate all rows into the allocated array
    strcpy(concatenated, "");
    for (int i = 1; i < argc; i++) {
        strcat(concatenated, argv[i]);
        strcat(concatenated, " ");
    }

    // Print the concatenated array
    printf("Concatenated array: %s\n", concatenated);

    // Free dynamically allocated memory
    free(concatenated);
	concatenated=NULL;

    return 0;
}
