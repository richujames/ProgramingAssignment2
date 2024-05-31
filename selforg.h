#ifndef SELFORG_H

#define SELFORG_H

#include <stdio.h>
#include <stdlib.h>
/*
 * Enumeration for different error handling scenarios. These are used to define
 * various error conditions that might occur during the program's execution.
 */
enum error_handling {
    MALLOC_FAILURE,      // Error when memory allocation fails
    INCORRECT_USAGE,     // Error for incorrect usage of functions
    FILE_OPEN_FAILURE,   // Error when file opening fails
    FILE_CLOSE_FAILURE,  // Error when file closing fails
    MAX_COUNT = 99       // Maximum count value for nodes
};

/*
 * Structure defining a node in the doubly linked list. Each node contains:
 * - data: the integer value stored in the node.
 * - count: the number of times this node has been accessed or inserted.
 * - prev: pointer to the previous node in the list.
 * - next: pointer to the next node in the list.
 */
struct node {
    int data;            // Data stored in the node
    int count;           // Count of accesses or insertions
    struct node* prev;   // Pointer to the previous node
    struct node* next;   // Pointer to the next node
};

/*
 * Function declarations for the linked list operations.
 */

/*
 * Creates an empty list by returning a NULL head pointer.
 * Returns: a NULL pointer indicating the list is empty.
 */
struct node* CreateEmptyList();

/*
 * Creates a new node with the given data.
 * Parameters:
 * - data: the integer value to be stored in the new node.
 * Returns: a pointer to the newly created node.
 */
struct node* CreateNode(int data);

/*
 * Searches for a node with the given key in the list.
 * Parameters:
 * - head: pointer to the head of the list.
 * - key: the integer value to search for.
 * Returns: a pointer to the node containing the key, or NULL if not found.
 */
struct node* Search(struct node* head, int key);

/*
 * Inserts a new node with the given data at the front of the list.
 * Parameters:
 * - headref: double pointer to the head of the list.
 * - data: the integer value to be inserted.
 */
void InsertAtFront(struct node** headref, int data);

/*
 * Deletes a node with a specific key from the list.
 * Parameters:
 * - headref: double pointer to the head of the list.
 * - key: the integer value of the node to be deleted.
 */
void DeleteNode(struct node** headref, int key);

/*
 * Prints the elements of the list.
 * Parameters:
 * - head: pointer to the head of the list.
 */
void PrintList(struct node* head);

/*
 * Deletes the entire list and frees the allocated memory.
 * Parameters:
 * - head: pointer to the head of the list.
 */
void DeleteList(struct node* head);

/*
 * Moves a node with a specific value to the front of the list.
 * Parameters:
 * - headref: double pointer to the head of the list.
 * - value: the integer value of the node to be moved.
 */
void MoveToFront(struct node** headref, int value);

/*
 * Function declarations for file operations.
 */

/*
 * Opens a file in read mode.
 * Parameters:
 * - name: the name of the file to be opened.
 * Returns: a pointer to the opened file, or NULL if the file could not be opened.
 */
FILE* openFile(char name[12]);

/*
 * Opens a file in write mode.
 * Parameters:
 * - name: the name of the file to be opened.
 * Returns: a pointer to the opened file, or NULL if the file could not be opened.
 */
FILE* writeIntoFile(char name[12]);

#endif // SELFORG_H
