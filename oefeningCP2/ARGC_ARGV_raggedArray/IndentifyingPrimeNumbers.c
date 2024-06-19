/*
7. **Identifying Prime Numbers:**
   Implement a program that determines if each element in every row of integers (passed via `argv`) is a prime number.
   Print a message indicating whether each number is prime or not.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    // Check if argc is at least 2 (since argv[0] is the program name)
    if (argc < 2) {
        printf("Usage: %s <row1> <row2> ... <rowN>\n", argv[0]);
        return 1;
    }

    // Iterate over each row provided in argv
    for (int i = 1; i < argc; i++) {
        // Convert each element in the current row to integer and check if prime
        for (int j = 0; argv[i][j] != '\0'; j++) {
            // Convert substring to integer
            int num = atoi(&argv[i][j]);

            // Check if the number is prime and print the result
            if (is_prime(num)) {
                printf("%d in row %d is prime\n", num, i);
            } else {
                printf("%d in row %d is not prime\n", num, i);
            }

            // Skip to next space or end of string to handle multi-digit numbers
            while (argv[i][j] != ' ' && argv[i][j] != '\0') {
                j++;
            }
        }
    }

    return 0;
}
