/*
Dynamic Allocation of Struct:

Definieer dezelfde Person struct.
Schrijf een programma dat dynamisch geheugen toewijst voor een Person struct en vervolgens de waarden van de leden instelt en afdrukt.
Vergeet niet om het geheugen vrij te geven na gebruik.

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person {
	char name[50];
	int age;
	float height;
};

int main()
{
	//dynamisch geheugen toewijzen voor de struct.
	struct Person *person = (struct Person*) malloc( sizeof(struct Person));
	
	if (person == NULL){
		fprintf(stderr,"Geheugen toewijzing mislukt\n");
		return 1;
		}	
	
	strcpy(person->name, "Alice");
	person->age = 25;
	person->height = 1.8;
	
	printf("Name : %s\n", person->name);
	printf("age : %d\n", person->age);
	printf("height : %.2f meter\n", person->height);
	
	free(person);  //niet vergeten geheugen terug vrijgeven na gebruik.
	
	return 0;
}
