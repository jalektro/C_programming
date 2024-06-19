/*
4. **Sorting Each Row:**
   Develop a program that sorts each row of integers passed as command line arguments (`argv`) in ascending order.
   Print each sorted row.
*/


#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers (for qsort)
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(int argc, char *argv[]) {
    // Check if argc is at least 2 (since argv[0] is the program name)
    if (argc < 2) {
        printf("Usage: %s <row1> <row2> ... <rowN>\n", argv[0]);
        return 1;
    }

    // Iterate over each row provided in argv
    for (int i = 1; i < argc; i++) {
        int row[argc - 1]; // Assuming all rows are of equal length

        // Convert each element in the current row to integer and store in array
        int k = 0;
        for (int j = 0; argv[i][j] != '\0'; j++) {
            row[k++] = atoi(&argv[i][j]);

            // Skip to next space or end of string to handle multi-digit numbers
            while (argv[i][j] != ' ' && argv[i][j] != '\0') {
                j++;
            }
        }

        // Sort the current row using qsort
        qsort(row, k, sizeof(int), compare);

        // Print the sorted row
        printf("Sorted row %d:", i);
        for (int j = 0; j < k; j++) {
            printf(" %d", row[j]);
        }
        printf("\n");
    }

    return 0;
}
