/*
Oefening 1: Basis Pointer Declaratie en Dereferencing
Beschrijving: Schrijf een C-programma dat een integer variabele en een pointer naar die integer declareert.
 Wijs een waarde toe aan de integer en gebruik de pointer om de waarde te wijzigen.
 Print de waarde voor en na de wijziging.
*/

#include <stdio.h>

int main (void){

int a = 10;
int *ptr_a = &a;

printf("A voor de aanpassing is %d\n", *ptr_a);

*ptr_a = 20;

printf("A na de aanpassing is %d\n", *ptr_a);


return 0;
}
