/*Exercise 6: Dynamic 2D Array
Task: Write a program that dynamically allocates memory for a 2D array (matrix) of integers using malloc. 
Initialize the matrix with values, print it, and free the memory.
*/

#include <stdio.h>
#include <stdlib.h>


int main (void){
	int rows = 3;
	int cols = 4;
	
	int **matrix = (int**) malloc (rows * sizeof(int *));
	 if (matrix == NULL)
	 {
		 printf("Memory allocation failed\n");		
		 return 1;
	 }
	 
	for(int i = 0; i<rows;i++){
		matrix[i] = (int*) malloc(cols * sizeof(int));
		if (matrix[i] == NULL) {
			printf("Memory allocation failed\n");
		
		//free the already 	allocated mem. 
		for( int j = 0; j<i; j++){
			free(matrix[j]);
		}
		free(matrix);
		return 1;
		}
	}
	
	for(int i = 0; i< rows; i++){
		for(int j = 0; j<cols; j++){
		matrix[i][j]= i*cols + j+1;	
		}
	}
	
	printf("print matrix\n");
	for(int i = 0; i< rows; i++){
		for(int j = 0; j<cols; j++){
		printf("%d ", matrix[i][j]);	
		}
		printf("\n");
	}
	
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

	
	
	return 0;
}