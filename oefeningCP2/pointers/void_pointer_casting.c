/*
Oefening 9: Void Pointers
Beschrijving: Schrijf een C-programma dat het gebruik van void pointers demonstreert.

Instructies:

1)	Declareer een int en een float variabele.
2)	Declareer een void pointer en wijs deze achtereenvolgens toe aan de int en float variabele.
3)	Gebruik typecasting om de waarden via de void pointer te printen.
*/

#include <stdio.h>

int main(void)
{
	int a = 10;
	float f= 20.5;
	void *ptr;
	
	ptr= &a;
	printf("waarde van a : %d\n", * (int*)ptr);
	
	ptr=&f;
	
	printf("Waarde van float: %.1f\n", *(float *) ptr);
		
	return 0;
}