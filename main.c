#include <stdio.h>
#include <stdlib.h>
#include "selforg.h"

/*
The main function of the program begins here. It first attempts to open the input file "selforg.dat"
and the output file "selforg.run". If the files are opened successfully, an integer variable is declared
to store the numbers read from the input file.
*/

int main() 
{                               
    FILE* input = openFile("selforg.dat");   // Opening input file
    FILE* output = writeIntoFile("selforg.run"); // Opening output file
    int num;                                 // Declaration of variable to store read numbers

/*
An empty list is created by initializing the head pointer. The program then enters a loop that continues
until the end of the input file is reached. For each number read from the input file, the list is searched
for a node containing that number. If the node is not found, the number is inserted at the front of the list.
If the node is found, it is moved to the front of the list.
*/

    struct node* head = CreateEmptyList();      // Creating an empty list
 
    while (fscanf(input, " %d", &num) != EOF) 
    
    {
        struct node* theNode = Search(head, num); // Searching for the node with the given number
        if (theNode == NULL) {                  // If the node is not found in the list
            InsertAtFront(&head, num);          // Inserting the number at the front of the list
        } else {                                // If the node is found in the list
            MoveToFront(&head, num);            // Moving the node to the front of the list
        }
    }

    /*
After processing all numbers from the input file, a pointer is initialized to traverse the list.
The program then enters a loop that continues until the end of the list is reached. For each node in the list,
its data and count are written to the output file. After writing, the pointer moves to the next node.
Finally, the input and output files are closed, the list is deleted to free memory, and the program exits
with a success status.
*/

    struct node* current = head;                // Initializing a pointer to traverse the list
    while (current != NULL) {                   // Looping through the list until the end is reached
        fprintf(output, "%d (%d) \n", current->data, current->count); // Writing the data and count of the current node to the output file
        current = current->next;                // Moving to the next node
    }

    fclose(input);                             // Closing the input file
    fclose(output);                            // Closing the output file
    DeleteList(head);                          // Deleting the entire list to free memory

    return 0;                                  // Exiting the program with success status
}

