/*
3. **Row-wise Average Calculation:**
   Implement a program that computes the average of each row of integers passed as command line arguments (`argv`).
   Print the average of each row.
   */
   
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if argc is at least 2 (since argv[0] is the program name)
    if (argc < 2) {
        printf("Usage: %s <row1> <row2> ... <rowN>\n", argv[0]);
        return 1;
    }

    // Iterate over each row provided in argv
    for (int i = 1; i < argc; i++) {
        int sum = 0;
        int count = 0;

        // Convert each element in the current row to integer and compute sum
        for (int j = 0; argv[i][j] != '\0'; j++) {
            // Convert substring to integer
            int num = atoi(&argv[i][j]);
            sum += num;
            count++;

            // Skip to next space or end of string to handle multi-digit numbers
            while (argv[i][j] != ' ' && argv[i][j] != '\0') {
                j++;
            }
        }

        // Calculate average of the current row
        double average = (double)sum / count;

        // Print the average of the current row
        printf("Average of row %d: %.2f\n", i, average);
    }

    return 0;
}
