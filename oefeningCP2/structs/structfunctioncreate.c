#include <stdio.h>
#include <string.h>
/*Function and Structs:

Definieer de struct Person zoals eerder.
Schrijf een functie die een Person als parameter neemt en de gegevens van die persoon print.
Schrijf een hoofdprogramma dat een Person maakt en de functie aanroept.
*/

struct Person {
	char name[50];
	int age;
	float height;
};

struct Person createPerson(char name[], int age, float height){
	struct Person p;
	strcpy(p.name, name);
	p.age = age;
	p.height = height;
	return p;
}

void printStruct(struct Person p){
	printf("Name : %s\n", p.name);
	printf("age : %d\n", p.age);
	printf("height : %.2f meter\n", p.height);
}


int main()
{
	struct Person person1 = createPerson("bob", 25, 1.8);
	/*	
	printf("Name : %s\n", person1.name);
	printf("age : %d\n", person1.age);
	printf("height : %.2f meter\n", person1.height);
	*/
	printStruct(person1);
	return 0;
}
