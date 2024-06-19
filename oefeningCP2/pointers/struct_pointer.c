/*
Oefening 8: Struct Pointers
Beschrijving: Schrijf een C-programma dat het gebruik van pointers naar structs demonstreert.

Instructies:

1) Definieer een struct struct Point met twee leden x en y.
2) Declareer een variabele van type struct Point en wijs waarden toe aan x en y.
3) Declareer een pointer naar struct Point en wijs deze toe aan de variabele.
4) Gebruik de pointer om de waarden van x en y te printen en te wijzigen.
*/

#include <stdio.h>

struct Point{
	int x;
	int y;
};

int main(void)
{
	struct Point point1 = {1,2};
	struct Point *ptr1 = &point1;
	
	printf("punt x: %d en punt y: %d voor de wijziging\n", ptr1->x, ptr1->y);
	
	printf("wijziging met pointer\n");
	ptr1->x= 10;
	ptr1->y = 20;
	
	printf("punt x: %d en punt y: %d na de wijziging\n", ptr1->x, ptr1->y);
	
	
	printf("wijziging gewoon\n");
	point1.x = 15;
	point1.y = 35;
	printf("punt x: %d en punt y: %d na de wijziging\n", ptr1->x, ptr1->y);
	
	return 0;
}