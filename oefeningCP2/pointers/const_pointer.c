/*
Oefening 7: Constante Pointers
Beschrijving: Schrijf een C-programma dat het gebruik van constante pointers en pointers naar constante variabelen demonstreert.

Instructies:

1) Declareer een constante integer variabele const int a = 50.
2) Declareer een pointer naar een constante const int *p1 en wijs deze toe aan a.
3) Declareer een constante pointer int *const p2 en wijs deze toe aan een andere integer variabele b.
4) Probeer de waarden te wijzigen via de pointers en noteer eventuele compilerfouten.
*/

#include <stdio.h>

int main(void)
{
	const int a = 50;
	const int* ptr1= &a;
	int b = 60;
	int *const ptr2 = &b;
	
	// a = 40; // compiler fout 
	  // *p1 = 100; // Compilerfout: p1 is een pointer naar een constante
    b = 70; // Toegestaan
    // p2 = &a; // Compilerfout: p2 is een constante pointer

    printf("Waarde van a: %d\n", a);
    printf("Waarde van b: %d\n", b);
	
	
	return 0;
}
