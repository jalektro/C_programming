#include <stdio.h>
/*
Nested Structs:

Definieer een struct genaamd Address met de leden char street[100], int number, en char city[50].
Definieer een struct genaamd Employee met de leden char name[50], int id, en een Address struct.
Schrijf een programma om de gegevens van een Employee in te voeren en af te drukken.
*/

struct Address{
	char street[100];
	int number;
	char city[50];
};

struct Employee{
	char name[50];
	int id;
	struct Address address;
};

int main()
{
	struct Employee employee;
	//invoer van de waarden
	
	printf("Please enter name of employee.\n");
	printf("Name: ");
	scanf("%s", employee.name);
	printf("ID: ");
	scanf("%d", &employee.id);
	printf("street: ");
	scanf("%s", employee.address.street);
	printf("number");
	scanf("%d",&employee.address.number);
	printf("city:");
	scanf("%s", employee.address.city);
	
	//printing the values: 
	
printf("Employee: %s with ID: %d.\nHis address is : %s %d.\n    \rCity: %s\n", employee.name, employee.id, employee.address.street, employee.address.number, employee.address.city);

	
	return 0;
}
