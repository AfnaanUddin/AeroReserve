#include "../include/headerAeroReserve.h"

void ExitSystem(struct Flight *head)
{
    // **Step 1: Check if there are any flights to clean up**
    if (head == NULL)
    {
        printf("No flights to clean up.\n"); // If there are no flights, print a message and exit the function
    }

    // **Step 2: Free all flights and their passengers**
    struct Flight *temp; // Temporary pointer to traverse through the flight list

    // **Step 3: Traverse the flight list and free each flight and its passengers**
    while (head != NULL)
    {
        temp = head;       // Save the current flight node
        head = head->next; // Move to the next flight in the list

        // **Step 4: Free the passengers for the current flight**
        struct Passenger *passengerTemp = temp->passengerListHead; // Temporary pointer to traverse the passenger list
        while (passengerTemp != NULL)
        {
            struct Passenger *toFree = passengerTemp; // Save the current passenger node to free
            passengerTemp = passengerTemp->next;      // Move to the next passenger
            free(toFree);                             // Free the passenger node
        }

        free(temp); // Free the current flight node
    }

    // **Step 5: Print exit message and terminate the program**
    printf("Exiting the system. Goodbye!\n");
    exit(0); // Exit the program (this will stop the execution of the program)
}