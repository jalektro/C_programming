/*
Oefening 3: Pointer naar Pointer
Beschrijving: Schrijf een C-programma dat een pointer naar een pointer demonstreert. 
Declareer een integer variabele, een pointer naar die integer en een pointer naar de pointer.
Gebruik de pointer naar de pointer om de waarde van de integer te wijzigen.
*/

#include <stdio.h>

int main(){
	int a =30;
	int *ptr = &a;
	int **ptr_to_ptr = &ptr;
	printf("A afgedrukt als a : %d\n", a);
	printf("A afgedrukt met de ptr: %d\n", *ptr);
	printf("A afgedrukt met pointer to pointer %d\n", **ptr_to_ptr);
	
	**ptr_to_ptr = 40;
	
	printf("De waarde van A na de wijziging: %d\n", **ptr_to_ptr);
	
	return 0;
}