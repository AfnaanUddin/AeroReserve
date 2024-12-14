#include "../include/headerAeroReserve.h"

// Function to search for a flight by its flight number
void searchFlight(struct Flight *head)
{
    // **Step 1: Check if the flight list is empty**
    if (head == NULL)
    {
        printf("There are no Flights:\n");
        return; // Return if there are no flights to search
    }

    int flightNum;       // Variable to store the flight number entered by the user
    int flightFound = 0; // Flag to indicate if the flight was found

    // **Step 2: Prompt the user to enter the flight number they want to search for**
    printf("Enter The Flight Number Which You Want to Find:\n");
    scanf("%d", &flightNum); // Read the flight number from the user

    struct Flight *temp = head; // Temporary pointer to traverse the flight list

    // **Step 3: Traverse the flight list to search for the flight**
    while (temp != NULL)
    {
        // **Step 4: Check if the current flight matches the entered flight number**
        if (flightNum == temp->flightNumber)
        {
            flightFound = 1; // Set the flag to indicate the flight was found

            // **Step 5: Print the details of the found flight**
            printf("The Flight was Found:\n\n");
            printf("Flight Number: %d\n", temp->flightNumber);
            printf("Flight Destination: %s\n", temp->destination);
            printf("Flight Total Seats: %d\n", temp->totalSeats);
            printf("Flight Available Seats: %d\n", temp->availableSeats);

            break; // Exit the loop as the flight is found
        }

        temp = temp->next; // Move to the next flight in the list
    }

    // **Step 6: If the flight wasn't found, display a message**
    if (!flightFound)
    {
        printf("The Flight with Flight Number %d can't be found so it can't be Deleted:\n", flightNum);
    }
}