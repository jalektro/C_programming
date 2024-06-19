/*Exercise: Student Record Management System
Objective:
Create a Student Record Management System in C that uses structs, pointers, dynamic memory allocation, ragged arrays, argc and argv, linked lists, and file handling.

Problem Statement:
Develop a C program that maintains a list of student records. Each student record contains the student's name, ID, and a ragged array of grades for different subjects. The program should allow adding new student records, displaying all records, and saving/loading records to/from a file.

Detailed Requirements:
Structs:

Define a Grade struct to store grades for a subject.
Define a Student struct to store student information including a ragged array of Grade.
Pointers and Dynamic Memory Allocation:

Use pointers to dynamically allocate memory for the student records and their grades.
Ragged Array:

Each student can have a different number of subjects and grades. Store the grades in a dynamically allocated array.
Command Line Arguments (argc and argv):

Use command line arguments to specify the input and output file names.
Linked List:

Store student records in a linked list to allow dynamic addition of records.
File Handling:

Implement functions to save the student records to a file and load them from a file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing grades
typedef struct Grade {
    char subject[50];
    int *grades;
    int numGrades;
} Grade;

// Struct for storing student information
typedef struct Student {
    char name[50];
    int id;
    Grade *grades;
    int numSubjects;
    struct Student *next;
} Student;

// Function prototypes
Student* createStudent(char *name, int id);
void addGrade(Student *student, char *subject, int *grades, int numGrades);
void addStudent(Student **head, Student *newStudent);
void displayStudents(Student *head);
void saveToFile(Student *head, const char *filename);
Student* loadFromFile(const char *filename);
void freeStudents(Student *head);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];

    Student *head = loadFromFile(inputFile);

    // Example of adding a new student and grades
    Student *newStudent = createStudent("John Doe", 123);
    int grades1[] = {85, 90, 78};
    addGrade(newStudent, "Math", grades1, 3);
    int grades2[] = {88, 92};
    addGrade(newStudent, "Science", grades2, 2);
    addStudent(&head, newStudent);

    displayStudents(head);
    saveToFile(head, outputFile);
    freeStudents(head);

    return 0;
}

Student* createStudent(char *name, int id) {
    Student *student = (Student*)malloc(sizeof(Student));
    strcpy(student->name, name);
    student->id = id;
    student->grades = NULL;
    student->numSubjects = 0;
    student->next = NULL;
    return student;
}

void addGrade(Student *student, char *subject, int *grades, int numGrades) {
    student->grades = (Grade*)realloc(student->grades, (student->numSubjects + 1) * sizeof(Grade));
    strcpy(student->grades[student->numSubjects].subject, subject);
    student->grades[student->numSubjects].grades = (int*)malloc(numGrades * sizeof(int));
    memcpy(student->grades[student->numSubjects].grades, grades, numGrades * sizeof(int));
    student->grades[student->numSubjects].numGrades = numGrades;
    student->numSubjects++;
}

void addStudent(Student **head, Student *newStudent) {
    newStudent->next = *head;
    *head = newStudent;
}

void displayStudents(Student *head) {
    Student *current = head;
    while (current != NULL) {
        printf("Name: %s, ID: %d\n", current->name, current->id);
        for (int i = 0; i < current->numSubjects; i++) {
            printf("  Subject: %s, Grades: ", current->grades[i].subject);
            for (int j = 0; j < current->grades[i].numGrades; j++) {
                printf("%d ", current->grades[i].grades[j]);
            }
            printf("\n");
        }
        current = current->next;
    }
}

void saveToFile(Student *head, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    Student *current = head;
    while (current != NULL) {
        fprintf(file, "%s %d %d\n", current->name, current->id, current->numSubjects);
        for (int i = 0; i < current->numSubjects; i++) {
            fprintf(file, "%s %d ", current->grades[i].subject, current->grades[i].numGrades);
            for (int j = 0; j < current->grades[i].numGrades; j++) {
                fprintf(file, "%d ", current->grades[i].grades[j]);
            }
            fprintf(file, "\n");
        }
        current = current->next;
    }

    fclose(file);
}

Student* loadFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return NULL;
    }

    Student *head = NULL;
    char name[50];
    int id, numSubjects;

    while (fscanf(file, "%s %d %d", name, &id, &numSubjects) != EOF) {
        Student *student = createStudent(name, id);
        for (int i = 0; i < numSubjects; i++) {
            char subject[50];
            int numGrades;
            fscanf(file, "%s %d", subject, &numGrades);
            int *grades = (int*)malloc(numGrades * sizeof(int));
            for (int j = 0; j < numGrades; j++) {
                fscanf(file, "%d", &grades[j]);
            }
            addGrade(student, subject, grades, numGrades);
            free(grades);
        }
        addStudent(&head, student);
    }

    fclose(file);
    return head;
}

void freeStudents(Student *head) {
    Student *current = head;
    while (current != NULL) {
        Student *next = current->next;
        for (int i = 0; i < current->numSubjects; i++) {
            free(current->grades[i].grades);
        }
        free(current->grades);
        free(current);
        current = next;
    }
}
