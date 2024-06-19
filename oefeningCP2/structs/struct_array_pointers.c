/*
Struct Arrays and Pointers:

Definieer dezelfde Person struct.
Schrijf een programma dat een array van 3 Person structs dynamisch toewijst.
Gebruik pointers om de gegevens van de personen in te stellen en af te drukken.
Vergeet niet om het geheugen vrij te geven.
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
	struct Person *people = (struct Person*) malloc( 3*(sizeof(struct Person)));
	
	if (people == NULL){
		fprintf(stderr,"Geheugen toewijzing mislukt\n");
		return 1;
		}	
	
	strcpy(people[0].name, "Alice");
	people[0].age = 25;
	people[0].height = 1.8;
	
	strcpy(people[1].name, "Bob");
    people[1].age = 25;
    people[1].height = 1.80;

    strcpy(people[2].name, "Carol");
    people[2].age = 28;
    people[2].height = 1.70;

    // Gebruik pointers om de gegevens van de personen af te drukken
    printf("Details of the 3 persons:\n");
    for (int i = 0; i < 3; i++) {
        printf("Person %d:\n", i + 1);
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Height: %.2f meters\n", people[i].height);
        printf("\n");
    }
	
	free(people);  //niet vergeten geheugen terug vrijgeven na gebruik.
	
	return 0;
}
