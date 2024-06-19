/*
9. **Row-wise Reverse Order:**
   Develop a program that reverses the order of elements in each row of integers passed as command line arguments (`argv`).
   Print each row in reverse order.

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

    // Iterate over each row provided in argv
    for (int i = 1; i < argc; i++) {
        // Calculate length of current row
        int len = strlen(argv[i]);

        // Print the current row in reverse order
        printf("Reversed row %d:", i);
        for (int j = len - 1; j >= 0; j--) {
            printf(" %c", argv[i][j]);
        }
        printf("\n");
    }

    return 0;
}
