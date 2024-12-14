#include "../include/headerAeroReserve.h"

struct Flight *removeFlight(struct Flight *head)
{
    // **Step 1: Check if the flight list is empty (no flights available)**
    if (head == NULL)
    {
        printf("There are no Flight available to be Deleted:\n");
        return head; // Return the head as it is (empty list)
    }

    int flightNum;       // Variable to store the flight number to be deleted
    int flightFound = 0; // Flag to indicate whether the flight is found or not

    // **Step 2: Ask the user to input the flight number they want to delete**
    printf("Enter the Flight Number you would like to delete:\n");

    // **Step 3: Read the flight number from the user and validate the input**
    if (scanf("%d", &flightNum) != 1)
    {
        printf("Invalid input. Please enter a valid flight number.\n");
        return head; // Return the head as is in case of invalid input
    }

    // **Step 4: Start traversing the list of flights**
    struct Flight *temp = head;

    while (temp != NULL)
    {
        // **Step 5: Check if the current flight's flight number matches the input**
        if (flightNum == temp->flightNumber)
        {
            // Flight found: Proceed to delete it
            printf("Deleting flight with Flight Number %d...\n", flightNum);

            flightFound = 1; // Set the flag indicating the flight was found

            // **Step 6: Adjust the links to remove the flight from the linked list**
            if (temp == head) // If the flight is at the head of the list
            {
                head = temp->next; // Move the head pointer to the next flight
                if (head)          // If there is a next flight
                {
                    head->prev = NULL; // Set the previous pointer of the new head to NULL
                }
            }
            else // If the flight is not the head of the list
            {
                if (temp->prev) // If there is a previous flight
                {
                    temp->prev->next = temp->next; // Link the previous flight to the next one
                }

                if (temp->next) // If there is a next flight
                {
                    temp->next->prev = temp->prev; // Link the next flight to the previous one
                }
            }

            // **Step 7: Free the passengers of the flight (if any) before deleting the flight node**
            struct Passenger *passengerTemp = temp->passengerListHead;
            while (passengerTemp != NULL)
            {
                struct Passenger *toFree = passengerTemp; // Store the passenger node to be freed
                passengerTemp = passengerTemp->next;      // Move to the next passenger
                free(toFree);                             // Free the current passenger
            }

            // **Step 8: Free the memory allocated for the flight node itself**
            free(temp);
            printf("Flight with Flight Number %d was Deleted successfully:\n", flightNum);

            return head; // Return the updated head of the list
        }

        temp = temp->next; // Move to the next flight in the list
    }

    // **Step 9: If the flight was not found, print an error message**
    if (!flightFound)
    {
        printf("The Flight with Flight Number %d wasn't found so it can't be Deleted:\n", flightNum);
        return head; // Return the head without changes
    }

    return head; // Return the head of the list (in case no flight was deleted)
}