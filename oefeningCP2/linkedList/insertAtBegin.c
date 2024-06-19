/*
### Exercise 2: Insert a Node at the Beginning of a Linked List

**Steps:**
1. Write a function `insertAtBeginning` that takes a pointer to the head of the linked list and an integer `newData`.
2. Allocate memory for a new node.
3. Set the `data` of the new node to `newData`.
4. Link the new node to the current head of the list.
5. Update the head pointer to point to the new node.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
	};

void displayList(struct Node* head)	;
void insertAtBeginning(struct Node** headRef, int newData);


int main( int argc, char* argv[])	{
	struct Node *head = NULL;
	struct Node *second = NULL;
	struct Node *third = NULL;
	
	//allocate 3 nodes on the heap	
	head = (struct Node*) malloc(sizeof(struct Node));
	second = (struct Node*) malloc(sizeof(struct Node));
	third = (struct Node*) malloc(sizeof(struct Node));

	head->data = 1;
	head->next = second;
	
	second->data = 2;
	second->next = third;
	
	third->data = 3;
	third->next = NULL;
	
	printf("linked list created\n");
	displayList(head);
	
	insertAtBeginning(&head, 4);
	printf("after adding new data\n");
	displayList(head);
		
	free(head);
	free(second);
	free(third);
	head=NULL;
	second=NULL;
	third= NULL;
	
	return 0;
}

void displayList(struct Node* head)	{
	struct Node *temp = head;
	while (temp != NULL){
	printf("%d -> ", temp->data);
	temp = temp->next;
	}
	printf("\n");
}

void insertAtBeginning(struct Node** headRef, int newData){
	struct Node* newNode= (struct Node*) malloc(sizeof(struct Node));
		if(newNode == NULL){
		printf("failed mem alloc newNode(start cleanup)\n");
		return;
		}
		newNode->data = newData;
		newNode->next=  *headRef;
		*headRef= newNode;
}

