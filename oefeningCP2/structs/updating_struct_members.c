/*
Updating Struct Members:

Definieer dezelfde Person struct.
Schrijf een functie die een pointer naar een Person als parameter neemt en de leeftijd van de persoon met 1 verhoogt.
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

void incrementAge(struct Person *p){
	p->age += 1;
}

int main()
{
	struct Person person1 = {"Alice", 25, 1.8};

   // Print de gegevens voor het verhogen van de leeftijd
    printf("Before incrementing age:\n");
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Height: %.2f meters\n", person1.height);
	
	incrementAge(&person1); // dereference here because the function expacts a pointer but person1 is not a pointer. 
 
     // Print de gegevens na het verhogen van de leeftijd
    printf("\nAfter incrementing age:\n");
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Height: %.2f meters\n", person1.height);
	
	return 0;
}
