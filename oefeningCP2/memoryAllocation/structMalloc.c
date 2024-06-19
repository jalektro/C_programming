/*
Exercise 8: Struct Allocation
Task: Define a struct Person with fields for name and age. Write a program that dynamically allocates memory
 for a Person struct, assigns values, prints them, and frees the memory.
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 
 typedef struct Person {
	char *name; 
	int age;
 } Person;
 
 int main(void)
 {
	Person *person = (Person *) malloc(sizeof(Person));
	 if (person == NULL) {
		 printf("Allocation failed\n");
		 return 1;
	 }
	 
	 person->name = (char *) malloc(50* sizeof(char));
	 if(person->name == NULL) {
		 printf("Allocation failed\n");
		 free(person);
		 return 1;
	 }
	 

	 strcpy(person->name, "John doe");
	 person->age = 32;
	 
printf("%s is %d old.\n",person->name, person->age);


free(person->name);
free(person);

	 
	 return 0;
 }