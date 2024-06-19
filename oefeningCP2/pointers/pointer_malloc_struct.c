/*
Oefening 10: Pointer naar Dynamisch Gealloceerde Struct
Beschrijving: Schrijf een C-programma dat geheugen dynamisch alloceert voor een struct en de gegevens via een pointer manipuleert.

Instructies:

1)	Definieer een struct struct Person met twee leden char name[50] en int age.
2)	Gebruik malloc om geheugen dynamisch toe te wijzen voor een struct Person.
3)	Wijs waarden toe aan de leden van de struct via de pointer.
4)	Print de waarden van de leden en bevrijd het toegewezen geheugen.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
char name[50];
int age;	
};

int main(void)
{
	struct Person *person = (struct Person *) malloc(sizeof(struct Person));
	
	if(person == NULL)	{
		printf("Geheugen allocatie mislukt\n");
		return 1;
	}
	
	strcpy(person->name, "Robert");
	person->age = 34;
	
	printf("%s is %d old.\n", person->name, person->age);
	
	free(person);
	
	return 0;
}