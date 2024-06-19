#include <stdio.h>
/*Struct Basics:

Definieer een struct genaamd Person met de volgende leden: char name[50], int age, en float height.
Schrijf een programma dat een variabele van type Person declareert, initialiseren en vervolgens de waarden van de leden print.
Array van Structs:

Definieer dezelfde Person struct.
Maak een array van 5 Person struct-variabelen.
Schrijf een programma om de gegevens van 5 personen in te voeren en af te drukken.


*/

struct Person {
	char name[50];
	int age;
	float height;
};

int main()
{
	struct Person people[5];
	
	for(int i = 0; i<5;i++)
	{
		printf("enter details for person %d: \n", i+1);
		printf("name: ");
		scanf("%s",people[i].name);
		printf("age:");
		scanf("%d",&people[i].age);
		printf("height:");
		scanf("%f",&people[i].height);
	}
	
	//afdrukken van de gegevens
	printf("Here are the details.\n");
	for(int i = 0; i<5;i++)
	{
	printf("Person%d:\n",i+1);
	printf("Name: %s\n",people[i].name);
	printf("Age: %d\n",people[i].age);
	printf("Height: %.2f\n\n",people[i].height);
	}

	return 0;
}
