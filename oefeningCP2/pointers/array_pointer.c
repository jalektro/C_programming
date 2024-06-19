/*
Oefening 5: Array van Pointers
Beschrijving: Schrijf een C-programma dat een array van pointers naar strings (karakterarrays) maakt. Initialiseer de array met namen van vijf vruchten en print vervolgens elke vruchtnaam.

Instructies:

1)	Declareer een array van pointers naar karakters char *fruits[5].
2)	Initialiseer de array met namen van vijf vruchten: "Apple", "Banana", "Cherry", "Date", "Elderberry".
3)	Gebruik een lus om elke vruchtnaam te printen.
*/

#include <stdio.h>
#include <string.h>


int main (void)
{
	char *fruits[5] = {"apple","Banana","cherry", "Date", "Elderberry"};
	
	for(int i =0; i<5; i++){
		printf("fruit %d : %s\n", i+1, fruits[i]);
	}
	return 0;
}
