/*
Comparing Structs:

Definieer dezelfde Person struct.
Schrijf een functie die twee Person structs als parameters neemt en vergelijkt op basis van leeftijd.
De functie moet teruggeven welke persoon ouder is of aangeven als ze dezelfde leeftijd hebben.
Schrijf een hoofdprogramma om deze functie te testen.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  //used forallocating memory 

struct Person {
	char name[50];
	int age;
	float height;
};

void compareAge(struct Person p1, struct Person p2)
{
	if (p1.age > p2.age)	{
		printf("%s is older than %s.\n", p1.name, p2.name);
	} else if (p1.age < p2.age)	{
		printf("%s is older than %s.\n", p2.name, p1.name);
	} else {
		printf("%s and %s are of the same age.\n", p1.name, p2.name);
	}
}

int main()
{
	struct Person person1 = {"Alice", 25, 1.8};
	struct Person person2 = {"Bob", 20, 1.5};



	printf("info for person1: \n");
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Height: %.2f meters\n", person1.height);
	
	printf("info for person2: \n");
    printf("Name: %s\n", person2.name);
    printf("Age: %d\n", person2.age);
    printf("Height: %.2f meters\n", person2.height);
	
	compareAge(person1, person2);
 
 
   
	
	return 0;
}
