/*
### Exercise 5: File Append

Write a program that prompts the user to enter a line of text and appends this line to a file (`log.txt`).
 If the file doesn’t exist, it should be created. Ensure proper error handling for file opening and writing operations.
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 
 int main(void)
 {
	 char input[1024];
	 
	 FILE *filePtr = fopen("log.txt" , "a");
	 if (filePtr == NULL){
		 printf("Failed to open the file.\n");
		 return 1;
	 }
	 
	 printf("Enter a line of text to append to log.txt: ");
	 if(fgets(input,sizeof(input),stdin)==NULL){
		 printf("Failed reading the file.\n");
		 fclose(filePtr);
		 return 1;
	 }
		     // Write the input to the file
    if (fputs(input, filePtr) == EOF) {
        perror("Error writing to file");
        fclose(filePtr);
        return 1;
    }

    // Close the file
    fclose(filePtr);

    printf("Text successfully appended to log.txt.\n");

	 return 0;
 }
 