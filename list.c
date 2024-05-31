#include <stdio.h>
#include <stdlib.h>
#include "selforg.h"

/*
This function creates an empty list by initializing the head pointer to NULL.
It returns NULL since the list is empty.
*/
struct node* CreateEmptyList() {
    struct node* head = NULL; // Initialize head pointer to NULL
    return head;              // Return NULL as the list is empty
}

/*
This function creates a new node with the given data. It allocates memory for the new node,
initializes its count field to 1, assigns the provided data, sets its previous and next pointers
to NULL, and then returns the newly created node.
 */
struct node* CreateNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node)); // Allocate memory for the new node
    newNode->count = 1;                                               // Initialize count field to 1
    newNode->data = data;                                             // Assign data to the new node
    newNode->prev = NULL;                                             // Set previous pointer to NULL
    newNode->next = NULL;                                             // Set next pointer to NULL
    return newNode;                                                   // Return the newly created node
}

/*
This function searches for a node with the given key in the list. It initializes a pointer to traverse the list,
loops through the list until the end is reached, and checks if the current node contains the key.
If found, it returns the pointer to the node containing the key; otherwise, it returns NULL.
 */
struct node* Search(struct node* head, int key) {
    struct node* currentNode = head; // Initialize pointer to traverse the list
    while (currentNode != NULL) {    // Loop through the list until the end is reached
        if (currentNode->data == key) { // Check if the current node contains the key
            return currentNode;         // Return the pointer to the node containing the key
        }
        currentNode = currentNode->next; // Move to the next node
    }
    return NULL; // Return NULL if key is not found in the list
}

/*
This function inserts a new node at the front of the list. It creates a new node with the given data,
checks if the list is not empty, updates the previous pointer of the current head, updates the next pointer
of the new node, and finally updates the head pointer to point to the new node.
*/
void InsertAtFront(struct node** headRef, int data) {
    struct node* newNode = CreateNode(data); // Create a new node with the given data
    if (*headRef != NULL) {                  // Check if the list is not empty
        (*headRef)->prev = newNode;          // Update the previous pointer of the current head
        newNode->next = *headRef;            // Update the next pointer of the new node
    }
    *headRef = newNode;                      // Update the head pointer to point to the new node
}

/*
This function deletes a node with a specific key from the list. It initializes a pointer to traverse the list,
loops through the list until the end is reached, and checks if the current node contains the key.
If found, it updates the pointers accordingly to remove the node from the list and frees the memory occupied by
the current node. The function exits after deleting the node or moves to the next node if the key is not found.
 */
void DeleteNode(struct node** headRef, int key) {
    struct node* currentNode = *headRef; // Initialize pointer to traverse the list
    while (currentNode != NULL) {        // Loop through the list until the end is reached
        if (currentNode->data == key) {  // Check if the current node contains the key
            if (currentNode == *headRef) { // Check if the current node is the head of the list
                *headRef = currentNode->next; // Update the head pointer to the next node
                if (currentNode->next != NULL) { // Check if there is a next node
                    currentNode->next->prev = NULL; // Update the previous pointer of the next node
                }
            } else { // If the current node is not the head
                if (currentNode->prev != NULL) { // Check if there is a previous node
                    currentNode->prev->next = currentNode->next; // Update the next pointer of the previous node
                }
                if (currentNode->next != NULL) { // Check if there is a next node
                    currentNode->next->prev = currentNode->prev; // Update the previous pointer of the next node
                }
            }
            free(currentNode); // Free the memory occupied by the current node
            return;           // Exit the function after deleting the node
        }
        currentNode = currentNode->next; // Move to the next node
    }
}

/*
This function prints the elements of the list. It initializes a pointer to traverse the list,
loops through the list until the end is reached, prints the data and count of the current node,
and moves to the next node.
*/
void PrintList(struct node* head) {
    struct node* currentNode = head; // Initialize pointer to traverse the list
    while (currentNode != NULL) {    // Loop through the list until the end is reached
        printf("%d, count = %d\n", currentNode->data, currentNode->count); // Print the data and count of the current node
        currentNode = currentNode->next; // Move to the next node
    }
}

/*
This function deletes the entire list. It initializes a pointer to traverse the list, loops through the list
until the end is reached, stores the current node in a temporary pointer, moves to the next node, and frees
the memory occupied by the current node.
 */
void DeleteList(struct node* head) {
    struct node* currentNode = head; // Initialize pointer to traverse the list
    while (currentNode != NULL) {    // Loop through the list until the end is reached
        struct node* tempNode = currentNode; // Store the current node in a temporary pointer
        currentNode = currentNode->next;     // Move to the next node
        free(tempNode);                      // Free the memory occupied by the current node
    }
}

/*
This function moves a node with a specific value to the front of the list. It searches for the node with the
given value in the list, checks if the node is not found or already at the front, and exits if no action is required.
If found, it increments the count of the node, updates the pointers accordingly to move the node to the front,
and updates the head pointer to point to the node.
 */
void MoveToFront(struct node** headRef, int value) {
    struct node* targetNode = Search(*headRef, value); // Search for the node with the given value in the list
    if (targetNode == NULL || targetNode == *headRef) { // Check if the node is not found or already at the front
        return; // Exit the function if no action is required
    }
    targetNode->count++; // Increment the count of the node
    if (targetNode->prev != NULL) { // Check if the node has a previous node
        targetNode->prev->next = targetNode->next; // Update the next pointer of the previous node
    }
    if (targetNode->next != NULL) { // Check if the node has a next node
        targetNode->next->prev = targetNode->prev; // Update the previous pointer of the next node
    }
    targetNode->next = *headRef; // Update the next pointer of the node to point to the current head
    if (*headRef != NULL) { // Check if the list is not empty
        (*headRef)->prev = targetNode; // Update the previous pointer of the current head
    }
    *headRef = targetNode; // Update the head pointer to point to the node
    targetNode->prev = NULL; // Set the previous pointer of the node to NULL as it is now the head
}
