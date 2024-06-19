#include <stdio.h>
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

void printStruct(struct Person p){
	printf("Name : %s\n", p.name);
	printf("age : %d\n", p.age);
	printf("height : %.2f meter\n", p.height);
}

int main()
{
	struct Person person1 = {"jan",20,1.80};
	
	printStruct(person1);
	return 0;
}
