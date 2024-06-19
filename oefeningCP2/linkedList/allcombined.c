#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // For boolean data type

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void displayList(struct Node* head);
void insertAtBeginning(struct Node** headRef, int newData);
void insertAtEnd(struct Node** headRef, int newData);
void deleteNode(struct Node** headRef, int key);
void reverseList(struct Node** headRef);
int countNodes(struct Node* head);
bool searchNode(struct Node* head, int key);
struct Node* getNthNode(struct Node* head, int index);
bool detectLoop(struct Node* head);
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2);

int main() {
    // Initialize three nodes
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // Allocate memory for three nodes
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Assign data and link nodes for Exercise 1: Create a Simple Linked List
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printf("Exercise 1: Linked list created:\n");
    displayList(head);

    // Exercise 2: Insert a Node at the Beginning of a Linked List
    insertAtBeginning(&head, 4);
    printf("Exercise 2: After inserting 4 at the beginning:\n");
    displayList(head);

    // Exercise 3: Insert a Node at the End of a Linked List
    insertAtEnd(&head, 5);
    printf("Exercise 3: After inserting 5 at the end:\n");
    displayList(head);

    // Exercise 4: Delete a Node from a Linked List
    deleteNode(&head, 2);
    printf("Exercise 4: After deleting node with data 2:\n");
    displayList(head);

    // Exercise 5: Reverse a Linked List
    reverseList(&head);
    printf("Exercise 5: After reversing the linked list:\n");
    displayList(head);

    // Exercise 6: Count the Number of Nodes in a Linked List
    int nodeCount = countNodes(head);
    printf("Exercise 6: Number of nodes in the linked list: %d\n", nodeCount);

    // Exercise 7: Search for an Element in a Linked List
    bool found = searchNode(head, 3);
    if (found) {
        printf("Exercise 7: Element 3 is found in the linked list.\n");
    } else {
        printf("Exercise 7: Element 3 is not found in the linked list.\n");
    }

    // Exercise 8: Get the Nth Node in a Linked List
    struct Node* nthNode = getNthNode(head, 2);
    if (nthNode != NULL) {
        printf("Exercise 8: Data of the node at index 2 (3rd node): %d\n", nthNode->data);
    } else {
        printf("Exercise 8: Index out of bounds.\n");
    }

    // Exercise 9: Detect a Loop in a Linked List
    bool hasLoop = detectLoop(head);
    if (hasLoop) {
        printf("Exercise 9: The linked list has a loop.\n");
    } else {
        printf("Exercise 9: The linked list does not have a loop.\n");
    }

    // Exercise 10: Merge Two Sorted Linked Lists
    // Create two sorted lists for merging
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* mergedList = NULL;

    // Example sorted lists for merging
    head1 = (struct Node*)malloc(sizeof(struct Node));
    head1->data = 1;
    head1->next = NULL;

    head2 = (struct Node*)malloc(sizeof(struct Node));
    head2->data = 2;
    head2->next = NULL;

    mergedList = mergeSortedLists(head1, head2);
    printf("Exercise 10: Merged sorted linked list:\n");
    displayList(mergedList);

    // Free allocated memory
    free(head);
    free(second);
    free(third);
    free(head1);
    free(head2);

    return 0;
}

// Function definitions

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAtBeginning(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Failed memory allocation for newNode\n");
        return;
    }
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

void insertAtEnd(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Failed memory allocation for newNode\n");
        return;
    }

    newNode->data = newData;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    struct Node* last = *headRef;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}

void deleteNode(struct Node** headRef, int key) {
    struct Node* temp = *headRef;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found in the linked list\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void reverseList(struct Node** headRef) {
    struct Node* prev = NULL;
    struct Node* current = *headRef;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *headRef = prev;
}

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

bool searchNode(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

struct Node* getNthNode(struct Node* head, int index) {
    struct Node* current = head;
    int count = 0;

    while (current != NULL) {
        if (count == index) {
            return current;
        }
        count++;
        current = current->next;
    }

    return NULL; // index out of bounds
}

bool detectLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }

    return false;
}

struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct Node* result = NULL;

    if (list1->data <= list2->data) {
        result = list1;
        result->next = mergeSortedLists(list1->next, list2);
    } else {
        result = list2;
        result->next = mergeSortedLists(list1, list2->next);
    }

    return result;
}
