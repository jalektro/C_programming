/*
circulairy linked list where data will be inserted with push front , pop front. push back and pop back is inserted.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
	int data;
	struct Node *next;
};

char step( void ); //used for step by step running true programmm when hit 0 enter go to next (while loops)
void printLinkedList( struct Node *head );

int main(void)
{
	srand(time(NULL));
	struct Node *head = NULL;
	
	//push back
	printLinkedList(head); //head should be empty.
	//Lets push on the back.
	while (step() != 0){
		if(head == NULL) {
			head = (struct Node *) calloc(1, sizeof(struct Node));
			head->data = rand() %100; 
			head->next = NULL; //there is no other data in the list.
		}
		else {
		struct Node *pointer = head;
		while(pointer->next != NULL){
		pointer = pointer->next;
		}
		pointer->next = (struct Node*)calloc(1,sizeof(struct Node));
		pointer->next->data = rand()%100;
		}
		printLinkedList(head);		
	}
	
	
return 0;	
}


char step( void )
{
	char in = getchar();
	//while (getchar() != '\n'); 
	(void)system( "cls" ); //use clear on linux and cls for windows.
	return in;
}

void printLinkedList( struct Node *head )
{
	if( head == NULL )
	{
		printf( "NULL\n\n" );
		return;
	}
	struct Node *pointer = head;
	int level = 0;
	printf( "   ╭─&%p\n", pointer );
	printf( "┏━━┷━━┓\n" );
	printf( "┃%5d┃\n", pointer->data );
	while( pointer->next != NULL && level < 16 )
	{
		pointer = pointer->next;
		if( pointer == head )
		{ // circular
			printf( "%*s┠┄┄┄┄┄┨\n", level * 9, "" );
			printf( "%*s┃  *  ┃\n", level * 9, "" );
			printf( "%*s┗━━━━━┛\n", level * 9, "" );
			printf( " ╱╷╲%*s│\n", level * 9 - 1, "" );
			printf( "  ╰" );
			for( int i = 0; i < 2 || i < level * 9; i++ )
				printf( "─" );
			printf( "╯\n" );
			return;
		}
		printf( "%*s┠┄┄┄┄┄┨     ╭─&%p\n", level * 9, "", pointer );
		printf( "%*s┃  *  ┃->┏━━┷━━┓\n", level * 9, "" );
		printf( "%*s┗━━━━━┛  ┃%5d┃\n", level * 9, "", pointer->data );
		level++;
	}
	printf( "%*s┠┄┄┄┄┄┨\n", level * 9, "" );
	printf( "%*s┃ NULL┃\n", level * 9, "" );
	printf( "%*s┗━━━━━┛\n\n", level * 9, "" );
}