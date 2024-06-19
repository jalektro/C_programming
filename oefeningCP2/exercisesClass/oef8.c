/*
Schrijf een programma waarbij een array van 100 verschillende 3D punten wordt gegenereerd.
 Kies vervolgens willekeurig één van deze punten als oorsprong. Sorteer dan de overige 99 punten volgens de euclidische afstand tot 
 deze oorsprong waarbij het dichtsbijzijnde punt als eerste element in de array staat. Sorteer de lijst daarna nog een keer maar deze 
 keer volgens de Manhattan afstand waarbij opnieuw het dichtsbijzinde punt als eerste element in de array staat. 
 Voor het sorteren maak je gebruik van de functie qsort(). Een pointer naar de juiste functie wordt meegegeven 
 als het argument voor de functie parameter int (*compar)(const void*,const void*).

struct Point3D
{
  float x, y, z;
};
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


struct Point3D
{
  float x, y, z;
};

// Functie om de Euclidische afstand te berekenen
float euclideanDistance(struct Point3D p1, struct Point3D p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

// Functie om de Manhattan afstand te berekenen
float manhattanDistance(struct Point3D p1, struct Point3D p2) {
    return fabs(p1.x - p2.x) + fabs(p1.y - p2.y) + fabs(p1.z - p2.z);
}

// Vergelijkingsfunctie voor qsort op basis van Euclidische afstand
int compareEuclidean(const void* a, const void* b, void* origin) {
    struct Point3D* pointA = (struct Point3D*)a;
    struct Point3D* pointB = (struct Point3D*)b;
    struct Point3D* originPoint = (struct Point3D*)origin;

    float distA = euclideanDistance(*pointA, *originPoint);
    float distB = euclideanDistance(*pointB, *originPoint);

    return (distA > distB) - (distA < distB);
}

// Vergelijkingsfunctie voor qsort op basis van Manhattan afstand
int compareManhattan(const void* a, const void* b, void* origin) {
    struct Point3D* pointA = (struct Point3D*)a;
    struct Point3D* pointB = (struct Point3D*)b;
    struct Point3D* originPoint = (struct Point3D*)origin;

    float distA = manhattanDistance(*pointA, *originPoint);
    float distB = manhattanDistance(*pointB, *originPoint);

    return (distA > distB) - (distA < distB);
}

int main (void){
	struct Point3D points[100];
	srand(time(0));
	
	//generationg 100points
	for(int i =0; i<100; i++){
		points[i].x = (float)(rand() %100);
		points[i].y = (float)(rand() %100);
		points[i].z = (float) (rand() %100);
	}
	//choose random point as origin element
	int originIndex = rand() %100;
	
	struct Point3D origin = points[originIndex];
	//print this origin center
	printf("Origin point is \n x: %.2f\ny: %.2f\nz: %.2f\n",origin.x, origin.y, origin.z);
	
	qsort_s(points, 100, sizeof(struct Point3D), (void *)compareEuclidean, &origin);
	printf("Sorted on euclidean distance.\n");
	for(int i= 0; i<100; i++){
		printf("(%.2f	%.2f	%.2f)\n",points[i].x,points[i].y, points[i].z);
		}
		
	qsort_s(points, 100, sizeof(struct Point3D), (void *)compareManhattan, &origin);
	printf("Sorted on Manhatten distance.\n");
	for(int i= 0; i<100; i++){
		printf("(%.2f	%.2f	%.2f)\n",points[i].x,points[i].y, points[i].z);
		}
	
	return 0;
}