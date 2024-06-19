/*
Exercise 1: Create a Simple Linked List
Steps:

Define a structure Node with two fields: data (integer) and next (pointer to Node).
Create three nodes dynamically using malloc.
Link the nodes together to form a linked list.
Display the elements of the linked list.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
	};
	
void displayList(struct Node* head)	{
	struct Node *temp = head;
	while (temp != NULL){
	printf("%d -> ", temp->data);
	temp = temp->next;
	}
	printf("\n");
}


int main( int argc, char* argv[])	{
	struct Node *head = NULL;
	struct Node * second = NULL;
	struct Node *third = NULL;
	
	//allocate 3 nodes on the heap
	
	head = (struct Node*) malloc(sizeof(struct Node));
	if (head == NULL){
		printf("failed mem alloc\n");
		return 1;
	}
	second = (struct Node*) malloc(sizeof(struct Node));
		if (second == NULL){
		printf("failed mem alloc\n");
		free(head);
		head = NULL;
		return 1;
	}
	third = (struct Node*) malloc(sizeof(struct Node));
		if (third == NULL){
		printf("failed mem alloc\n");
		free(head);
		free(second);
		head = NULL;
		second = NULL;
		return 1;
	}
	
	head->data = 1;
	head->next = second;
	
	second->data = 2;
	second->next = third;
	
	third->data = 3;
	third->next = NULL;
	
	printf("linked list created\n");
	displayList(head);
	
	free(head);
	free(second);
	free(third);
	head=NULL;
	second=NULL;
	third= NULL;
	
	return 0;
}