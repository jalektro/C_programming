/*
Oefening 4: Dynamische Geheugenallocatie
Beschrijving: Schrijf een C-programma dat geheugen dynamisch alloceert voor een array met behulp van malloc.
Initialiseer de array met waarden, print ze en bevrijd dan het gealloceerde geheugen.
1) Gebruik malloc om geheugen dynamisch toe te wijzen voor een array van 5 integers.
2) Initialiseer de array met waarden 10, 20, 30, 40, 50.
3) Print de waarden van de array.
4) Bevrijd het toegewezen geheugen.
*/

#include <stdio.h>
#include <stdlib.h>

int main (void){
	int *arr = (int*) malloc (5 * sizeof(int));
	
	if(arr == NULL){
		printf("geheugenallocatie mislukt\n");
		return 1;
	}
	for(int i =0; i<5; i++){
	arr[i] = (i+1)*10;
	printf("Element %d: %d\n", i, arr[i]);
	}
	
	free(arr);
	return 0;
}