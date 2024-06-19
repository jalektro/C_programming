/*
Oefening: Gebruik van Struct en Union
Omschrijving: Definieer een struct genaamd Student met leden voor de naam van de student en een union die verschillende soorten scores kan opslaan: 
cijfer (integer), percentage (float), of een beoordeling (char). Schrijf een programma om de gegevens van een student in te voeren en af te drukken,
 waarbij de union wordt gebruikt om slechts één type score op te slaan.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>  //used forallocating memory 

union Score {
	int grade;
	float percentage;
	char rating;
};

struct Student{
	char name[50];
	union Score score;
	int scoreType;    //1= grade 2 = percentage 3= rating
};

// Functie om de gegevens van de student in te voeren
void inputStudent(struct Student *student) {
    printf("Enter student's name: ");
    fgets(student->name, sizeof(student->name), stdin);
    student->name[strcspn(student->name, "\n")] = '\0'; // Verwijder de newline karakter

    printf("Select score type:\n");
    printf("1. Grade (integer)\n");
    printf("2. Percentage (float)\n");
    printf("3. Rating (char)\n");
    printf("Enter choice: ");
    scanf("%d", &student->scoreType);

    switch (student->scoreType) {
        case 1:
            printf("Enter grade: ");
            scanf("%d", &student->score.grade);
            break;
        case 2:
            printf("Enter percentage: ");
            scanf("%f", &student->score.percentage);
            break;
        case 3:
            printf("Enter rating: ");
            scanf(" %c", &student->score.rating);
            break;
        default:
            printf("Invalid choice!\n");
            exit(1);
    }
}

// Functie om de gegevens van de student af te drukken
void printStudent(struct Student student) {
    printf("Student's Name: %s\n", student.name);
    switch (student.scoreType) {
        case 1:
            printf("Grade: %d\n", student.score.grade);
            break;
        case 2:
            printf("Percentage: %.2f\n", student.score.percentage);
            break;
        case 3:
            printf("Rating: %c\n", student.score.rating);
            break;
        default:
            printf("Invalid score type!\n");
    }
}


int main()
{
	struct Student student;

    // Gegevens van de student invoeren
    inputStudent(&student);

    // Gegevens van de student afdrukken
    printStudent(student); 
	
	return 0;
}
