/*
8. **Searching for Element:**
   Write a program that searches for a specified integer in each row of integers passed as command line arguments (`argv`).
   Print the position (index) of the integer in each row, or a message indicating it wasn't found.
   */
   
   #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to search for an integer in a row
int search(int num, char *row) {
    int index = 0;
    for (int j = 0; row[j] != '\0'; j++) {
        int current_num = atoi(&row[j]);
        if (current_num == num) {
            return index;
        }
        // Skip to next space or end of string to handle multi-digit numbers
        while (row[j] != ' ' && row[j] != '\0') {
            j++;
        }
        index++;
    }
    return -1; // Return -1 if the number is not found
}

int main(int argc, char *argv[]) {
    // Check if argc is at least 3 (since argv[0] is the program name)
    if (argc < 3) {
        printf("Usage: %s <integer> <row1> <row2> ... <rowN>\n", argv[0]);
        return 1;
    }

    // Convert the first argument to integer (the number to search for)
    int num_to_search = atoi(argv[1]);

    // Iterate over each row provided in argv starting from argv[2]
    for (int i = 2; i < argc; i++) {
        // Search for num_to_search in the current row (argv[i])
        int index = search(num_to_search, argv[i]);

        // Print the result
        if (index != -1) {
            printf("%d found at index %d in row %d\n", num_to_search, index, i - 1);
        } else {
            printf("%d not found in row %d\n", num_to_search, i - 1);
        }
    }

    return 0;
}
