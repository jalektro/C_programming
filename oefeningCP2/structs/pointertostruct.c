
/*
Pointer to Struct:

Definieer dezelfde Person struct.
Schrijf een programma dat een Person declareert en een pointer naar deze struct.
Gebruik de pointer om de waarden van de leden in te stellen en af te drukken.
*/
#include <stdio.h>
#include <string.h>

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
	//declareer een variabele van type struct.
	struct Person person ;
	
	//declareer een pointer naar de Person struct.
	struct Person *ptr_person;
	
	//wijs het adres van person toe aan de pointer.
	ptr_person= &person;
	
	//gebruik de pointer om de waarden van de leden in te stellen.
	
	strcpy(ptr_person->name, "Alice");
	ptr_person->age = 25;
	ptr_person->height = 1.8;
	
	printf("Name : %s\n", ptr_person->name);
	printf("age : %d\n", ptr_person->age);
	printf("height : %.2f meter\n", ptr_person->height);
	
	return 0;
}
