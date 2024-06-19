/*
### Exercise 6: File Random Access

Write a program that demonstrates random access to a binary file (`data.bin`).
 Implement functions to read and write records at specific positions in the file.
 Records can be a struct with fields like ID, name, age, etc.
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 
 #define FILENAME "data.bin"
 
 typedef struct {
	 int ID;
	 char name[50];
	 int age;
 }Record;
 
void writeRecord(FILE *filePtr, int position, Record *record);
void read_record(FILE *filePtr, int position, Record *record);
void print_record(Record *record);

 int main (void)
{
	FILE *filePtr = fopen(FILENAME, "wb+");
		if (filePtr == NULL) {
		printf("failed to open file.\n");
		return 1;
		}
	
	//example records.
    Record rec1 = {1, "Alice", 30};
    Record rec2 = {2, "Bob", 25};
    Record rec3 = {3, "Charlie", 28};
	
	writeRecord(filePtr, 0 , &rec1);
	writeRecord(filePtr, 1 , &rec2);
	writeRecord(filePtr, 2 , &rec3);
	
	
	rewind(filePtr); 
	
	 // Read records from specific positions
    Record rec;
    read_record(filePtr, 1, &rec);
    print_record(&rec);	

    read_record(filePtr, 0, &rec);
    print_record(&rec);	

    read_record(filePtr, 2, &rec);
    print_record(&rec);

	fclose(filePtr);
	 
	 return 0;
 }
 
 void writeRecord(FILE *filePtr, int position, Record *record)	{
//	 int fseek( FILE *stream, long offset, int origin );

	 fseek(filePtr, position *sizeof(Record), SEEK_SET );  //SEEK_SET is measered from beginning
	 fwrite(record,sizeof(Record), 1, filePtr);	 
	 return; 
 }
 
 
void read_record(FILE *filePtr, int position, Record *record) {
    fseek(filePtr, position * sizeof(Record), SEEK_SET);
    fread(record, sizeof(Record), 1, filePtr);
}

void print_record(Record *record) {
    printf("ID: %d\n", record->ID);
    printf("Name: %s\n", record->name);
    printf("Age: %d\n\n", record->age);
}
 