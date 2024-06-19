/*
Finding Maximum Element:
Create a program that accepts rows of integers through command line arguments (argv) and determines the maximum element in each row.
 Print the maximum element of each row.
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <limits.h> // for INT_MIN  this i the minimum int that exist in C
 
 int main( int argc, char * argv[])	{
	 
	 if (argc < 2){
		 printf("Usage : %s <row1> <row2> <rowN>\n", argv[0]);
		 return 1;
	 }
	 
	//iterate over each argv 
	
	for(int i =1; i<argc; i++)	{
		int max = INT_MIN;
		
		for (int j= 0; argv[i][j] != '\0'; j++)	{
		int num = atoi(&argv[i][j]);
			if(num> max){
			max = num;
			}
				while(argv[i][j] != ' ' && argv[i][j] != '\0')	{
				j++;
				}
		}
		printf("the max elemenet of row %d : %d\n", i, max);
	}
	 
	 return 0;
 }