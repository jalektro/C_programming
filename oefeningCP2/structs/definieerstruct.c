#include <stdio.h>
/*Struct Basics:

Definieer een struct genaamd Person met de volgende leden: char name[50], int age, en float height.
Schrijf een programma dat een variabele van type Person declareert, initialiseren en vervolgens de waarden van de leden print.

*/

struct Person {
	char name[50];
	int age;
	float height;
};

int main()
{
	struct Person person1 = {"jan",20,1.80};
	
	printf("Name : %s\n", person1.name);
	printf("age : %d\n", person1.age);
	printf("height : %.2f meter\n", person1.height);
	return 0;
}
