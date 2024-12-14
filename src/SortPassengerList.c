#include "../include/headerAeroReserve.h"

// Function to sort passengers by seat number using insertion sort
struct Flight *SortPassengerListBySeat(struct Flight *head)
{
    // **Step 1: Check if the flight list is empty**
    if (head == NULL)
    {
        printf("There are no flights available.\n");
        return head; // Return the head (which is NULL) if there are no flights
    }

    int flightNum; // Variable to store the flight number entered by the user
    // **Step 2: Get the flight number from the user**
    printf("Enter the Flight Number on which you want to sort the passengers by seat:\n");
    scanf("%d", &flightNum); // Read the flight number from the user

    struct Flight *temp = head; // Temporary pointer to traverse the flight list
    int flightFound = 0;        // Flag to indicate if the flight with the given number is found

    // **Step 3: Find the flight with the given flight number**
    while (temp != NULL)
    {
        if (flightNum == temp->flightNumber) // Check if the current flight matches the entered flight number
        {
            flightFound = 1; // Set the flag indicating the flight was found

            struct Passenger *originalHead = temp->passengerListHead; // Pointer to the original passenger list
            struct Passenger *sortedList = NULL;                      // Pointer to the new sorted passenger list

            // **Step 4: Check if there are passengers to sort**
            if (originalHead == NULL)
            {
                printf("There are no passengers available on this flight to be sorted.\n");
                return head; // Return the flight list without any sorting if there are no passengers
            }

            // **Step 5: Insertion sort logic to sort passengers by seat number**
            while (originalHead != NULL)
            {
                struct Passenger *current = originalHead; // Pointer to the current passenger
                originalHead = originalHead->next;        // Move to the next passenger in the original list

                // **Insert the current passenger into the sorted list**
                if (sortedList == NULL || current->seatNumber < sortedList->seatNumber)
                {
                    // Insert at the beginning of the sorted list
                    current->next = sortedList;
                    current->prev = NULL;
                    if (sortedList != NULL)
                    {
                        sortedList->prev = current; // Update the previous pointer of the old first passenger
                    }
                    sortedList = current; // Update the sorted list head
                }
                else
                {
                    // **Find the correct position to insert the current passenger in the sorted list**
                    struct Passenger *tempSorted = sortedList;
                    while (tempSorted->next != NULL && tempSorted->next->seatNumber < current->seatNumber)
                    {
                        tempSorted = tempSorted->next; // Move to the next passenger in the sorted list
                    }

                    // **Insert in the middle or end of the sorted list**
                    current->next = tempSorted->next;
                    tempSorted->next = current;
                    current->prev = tempSorted;

                    // If the current passenger is not the last passenger, update the next passenger's prev pointer
                    if (current->next != NULL)
                    {
                        current->next->prev = current; // Update the previous pointer of the next passenger
                    }
                }
            }

            // **Step 6: Update the head of the passenger list**
            temp->passengerListHead = sortedList; // Update the flight's passenger list head to the sorted list

            // **Step 7: Ensure the last passenger's next pointer is NULL**
            if (sortedList != NULL)
            {
                struct Passenger *last = sortedList; // Pointer to traverse the sorted list to the last passenger
                while (last->next != NULL)
                {
                    last = last->next; // Move to the next passenger in the sorted list
                }
                last->next = NULL; // Set the last passenger's next pointer to NULL to mark the end of the list
            }

            printf("Passengers sorted by seat number successfully.\n");
            return head; // Return the updated flight list
        }

        temp = temp->next; // Move to the next flight in the list
    }

    // **Step 8: If the flight wasn't found, display a message**
    if (!flightFound)
    {
        printf("The flight with flight number %d wasn't found.\n", flightNum); // Flight not found
        return head;                                                           // Return the original flight list
    }

    return head; // Return the original head if no changes were made
}