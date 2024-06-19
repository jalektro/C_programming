/*
10. **Matrix Transposition:**
    Implement a program that transposes the matrix represented by rows of integers passed as command line arguments (`argv`).
	Print the transposed matrix.
*/


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if argc is at least 2 (since argv[0] is the program name)
    if (argc < 2) {
        printf("Usage: %s <row1> <row2> ... <rowN>\n", argv[0]);
        return 1;
    }

    // Determine number of rows (argc - 1) and maximum length of rows
    int num_rows = argc - 1;
    int max_length = 0;
    for (int i = 1; i < argc; i++) {
        int len = 0;
        while (argv[i][len] != '\0') {
            len++;
        }
        if (len > max_length) {
            max_length = len;
        }
    }

    // Allocate memory for transposed matrix
    char **transposed = (char **)malloc(max_length * sizeof(char *));
    for (int i = 0; i < max_length; i++) {
        transposed[i] = (char *)malloc(num_rows * sizeof(char));
    }

    // Populate the transposed matrix
    for (int i = 1; i < argc; i++) {
        int len = strlen(argv[i]);
        for (int j = 0; j < len; j++) {
            transposed[j][i - 1] = argv[i][j];
        }
    }

    // Print the transposed matrix
    printf("Transposed matrix:\n");
    for (int i = 0; i < max_length; i++) {
        for (int j = 0; j < num_rows; j++) {
            printf("%c ", transposed[i][j]);
        }
        printf("\n");
    }

    // Free dynamically allocated memory
    for (int i = 0; i < max_length; i++) {
        free(transposed[i]);
    }
    free(transposed);

    return 0;
}
