#include "../include/headerAeroReserve.h"

struct Flight *RemovePassenger(struct Flight *head)
{
    // **Step 1: Check if the flight list is empty (no flights available)**
    if (head == NULL)
    {
        printf("There are No Flights Available so you can't remove a passenger:\n");
        return head; // Return the head as it is (empty list)
    }

    int flightNum, pId;  // Variables to store flight number and passenger ID
    int flightFound = 0; // Flag to indicate whether the flight is found or not

    // **Step 2: Ask the user to input the flight number from which they want to remove a passenger**
    printf("Enter the Flight Number from which you want to remove a Passenger:\n");
    scanf("%d", &flightNum); // Read the flight number

    // **Step 3: Traverse the flight list to find the flight**
    struct Flight *temp = head;

    while (temp != NULL)
    {
        // **Step 4: Check if the current flight's flight number matches the input**
        if (flightNum == temp->flightNumber)
        {
            flightFound = 1; // Set the flag indicating the flight was found

            // **Step 5: Check if there are no passengers on the flight**
            if (temp->passengerListHead == NULL)
            {
                printf("There are no passengers on flight number %d to remove.\n", flightNum);
                return head; // Return the head as is (no passengers to remove)
            }

            // **Step 6: Ask the user to input the passenger ID to be removed**
            printf("Enter the Id of the passenger you want to remove:\n");
            scanf("%d", &pId); // Read the passenger ID

            struct Passenger *temp1 = temp->passengerListHead; // Pointer to traverse the passenger list
            int passengerFound = 0;                            // Flag to indicate whether the passenger is found

            // **Step 7: Traverse the passenger list to find the passenger**
            while (temp1 != NULL)
            {
                // **Step 8: Check if the passenger ID matches the input**
                if (pId == temp1->id)
                {
                    passengerFound = 1; // Set the flag indicating the passenger was found

                    // **Step 9: Handle removing the passenger from the list based on its position**
                    if (temp1 == temp->passengerListHead) // If the passenger is at the head of the list
                    {
                        temp->passengerListHead = temp1->next; // Move the head pointer to the next passenger
                        if (temp->passengerListHead != NULL)   // If there is a next passenger
                        {
                            temp->passengerListHead->prev = NULL; // Set the previous pointer of the new head to NULL
                        }
                        else
                        {
                            temp->passengerListTail = NULL; // If the list becomes empty, set the tail to NULL
                        }
                    }
                    else if (temp1 == temp->passengerListTail) // If the passenger is at the tail of the list
                    {
                        temp->passengerListTail = temp1->prev; // Move the tail pointer to the previous passenger
                        if (temp->passengerListTail != NULL)   // If there is a previous passenger
                        {
                            temp->passengerListTail->next = NULL; // Set the next pointer of the new tail to NULL
                        }
                    }
                    else // If the passenger is in the middle of the list
                    {
                        temp1->prev->next = temp1->next; // Link the previous passenger to the next one
                        temp1->next->prev = temp1->prev; // Link the next passenger to the previous one
                    }

                    // **Step 10: Free the memory allocated for the removed passenger**
                    free(temp1);

                    // **Step 11: Increment the available seats for the flight**
                    temp->availableSeats++;

                    printf("Passenger was removed Successfully:\n");
                    return head; // Return the updated head of the list
                }

                temp1 = temp1->next; // Move to the next passenger
            }

            // **Step 12: If the passenger was not found, prompt the user for retry**
            if (!passengerFound)
            {
                printf("The passenger with Id %d wasn't found. Try again? (Y/N):\n", pId);
                char choice;           // Variable to store user's choice for retrying
                scanf(" %c", &choice); // Read the user's choice

                // **Step 13: If the user wants to retry, call the function recursively**
                if (choice == 'Y' || choice == 'y')
                {
                    return RemovePassenger(head); // Recursively call the function for retry
                }
                return head; // Return the head without changes if user doesn't want to retry
            }
        }

        temp = temp->next; // Move to the next flight
    }

    // **Step 14: If the flight was not found, print an error message**
    if (!flightFound)
    {
        printf("The Flight with flight number %d wasn't found:\n", flightNum);
    }

    return head; // Return the head of the list (in case no passenger was removed)
}