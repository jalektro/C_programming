/*
Exercise 7: Linked List Implementation
Task: Implement a simple linked list where each node is dynamically allocated using malloc. 
Include functions to insert a node at the beginning, delete a node, and print the list. Free all allocated memory before exiting.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;
	
void insertAtHead(Node **head, int data){
	Node *newNode = (Node *) malloc( sizeof(Node));
	if (newNode == NULL){
		printf("allocation failed\n");
		return;
	}
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

void deleteNode(Node **head, int key){
	Node *temp = *head;
	Node *prev = NULL;
	
	//if the head node itself hold the key data
	if(temp != NULL && temp->data == key)	{
	*head = temp->next;
	free(temp);
	return;
	}
	
	//search for the value of key(data) in the list
	while(temp != NULL && temp->data != key){
		prev = temp;
		temp = temp->next;
	}
	
	if (temp== NULL){
		printf("Node with value %d not found\n", key);
		return;
	}
	
	//unlock node from the list
	prev->next = temp->next;
	free(temp);	
}

void printNodes(Node *head){
	Node *temp = head; 
		while (temp != NULL){
		printf("%d -> ", temp->data);
		temp = temp->next;
		}
		printf("NULL\n");
}

void freeNodes(Node *head){
	Node *temp;
	while (head != NULL){
	temp = head;
	head = head->next;
	free(temp);
	}
}
	
int main(void)
{
	Node *head = NULL;
	
	insertAtHead(&head, 10);
		insertAtHead(&head, 20);
	insertAtHead(&head, 30);
	insertAtHead(&head, 400);

printNodes(head);
	
	deleteNode(&head, 20);
	
	printf("after deleting 20\n");
	printNodes(head);
	
	freeNodes(head);
	
	return 0;
}