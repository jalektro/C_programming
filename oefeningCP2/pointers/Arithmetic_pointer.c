/*
Pointer Aritmetica
Beschrijving: Schrijf een C-programma dat pointer aritmetica demonstreert. 
Declareer een array en gebruik een pointer om door de array te itereren en elk element te printen.
*/

#include <stdio.h>

int main(){
	int arr[5] = {1,2,3,4,5};
	int *ptr = arr; // pointer verwijst naar het eerste item van de pointer dus arr[0]
	
	for (int i= 0; i<5; i++){
		printf("Element %d : %d\n", i, *(ptr++));
	}
	return 0;
}
