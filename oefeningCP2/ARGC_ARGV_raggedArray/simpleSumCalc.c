/*
1. **Simple Sum Calculation:**
   Write a program that takes multiple rows of integers as command line arguments (`argv`) and
   computes the sum of each row. Assume each row length is specified by `argc`. Print the sum of each row.
   */
   
   #include <stdio.h>
   #include <stdlib.h>
   
   
   int main( int argc, char * argv[])
   {
	   //always check if argc is at least 2 (ARGV[0] is the program name.)
	if(argc < 2)	{
		printf("Usage: %s <row1> <row2> .... <rowN>\n", argv[0]);
		return 1;
	}
	
	//iterate over each row provided in argv
		for (int i = 1; i< argc; i++)	{
			int sum = 0;
			for(int j = 0; argv[i][j] != '\0'; j++){
				sum += atoi(&argv[i][j]);
				//skip the spaece or end of string to handle multi-digit numbers
				while (argv[i][j] != ' ' && argv[i][j] != '\0') {
					j++;
				}
			}
				printf("sum of row %d: %d\n", i, sum);
		}
	return 	0;
   }
   