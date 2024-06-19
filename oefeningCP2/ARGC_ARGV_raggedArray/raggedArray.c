/*
Write a C program that creates a ragged array to store the number of students in each class of a school.
 Each class has a different number of students. The program should:

Dynamically allocate memory for the ragged array.
Read the number of students for each class from the user.
Print the number of students in each class.
Steps:

Define the number of classes.
Allocate memory for the array of pointers (each pointing to a sub-array).
For each class, allocate memory for the number of students.
Read the number of students for each class from the user.
Print the number of students for each class.
Free the allocated memory.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	srand(time(NULL));
	int classNumbers =	rand()%6+5;//Define the number of classes. random between 5 and 10.
	
	printf("classNumbers %d\n", classNumbers);
	
	int **students =(int**) malloc(classNumbers * sizeof(int*));	 //Allocate memory for the array of pointers (each pointing to a sub-array).
	//// Step 3: For each class, randomly generate the number of students between 10 and 30
	for(int i = 0; i< classNumbers;i++){
	int numStudents= rand()%21 +10;
	students[i] = (int *)malloc(numStudents * sizeof(int));
	
	//store of the students
	students[i][0] = numStudents;
	}
	
	printf("\nNumber of students in each class: \n");
	for (int i = 0; i< classNumbers;i++){
		printf("class %d: %d students.\n", i+1, students[i][0]);
	}
	
	//free memory
	for (int i = 0; i< classNumbers;i++){
	free(students[i]);
	}
	free(students);
	
	return 0;
}