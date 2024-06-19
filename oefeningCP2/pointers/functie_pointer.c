/*
Oefening 6: Functie Pointer
Beschrijving: Schrijf een C-programma dat een functiepointer demonstreert. 
Declareer een functie die twee integers optelt en een pointer naar deze functie.

Instructies:

1) Schrijf een functie int add(int a, int b) die de som van twee integers retourneert.
2) Declareer een functiepointer int (*func_ptr)(int, int) en wijs deze toe aan de add functie.
3) Gebruik de functiepointer om twee integers op te tellen en print het resultaat.
*/

#include <stdio.h>

int add(int a, int b);

int main (void){
	
	//func_ptr is a pointer to the function ADD. 
	int (*func_ptr)(int,int) = add;
	
	int result = func_ptr(10,20); // what it does is calling the function add with value 10 and 20. 
	
	printf("Het resultaat is : %d\n", result);
	
	return 0;
}


int add(int a, int b){
return a + b;
}