#include "../include/headerAeroReserve.h"

void ViewPassengerList(struct Flight *head)
{
    // **Step 1: Check if the flight list is empty**
    if (head == NULL)
    {
        printf("There are no flights available.\n");
        return; // Return if there are no flights to view
    }

    int flightNum; // Variable to store the flight number entered by the user
    printf("Enter the flight number for which you want to view the passenger list:\n");

    // **Step 2: Input validation for the flight number**
    if (scanf("%d", &flightNum) != 1) // Check if the input is valid
    {
        printf("Invalid input. Please enter a valid flight number.\n");
        return; // Return if the input is invalid
    }

    struct Flight *temp = head; // Temporary pointer to traverse the flight list
    int flightFound = 0;        // Flag to indicate if the flight with the given flight number is found

    // **Step 3: Search for the flight with the given flight number**
    while (temp != NULL)
    {
        if (flightNum == temp->flightNumber) // Check if the current flight matches the entered flight number
        {
            flightFound = 1; // Set the flag indicating the flight was found

            // **Step 4: Check if there are passengers on the flight**
            if (temp->passengerListHead == NULL)
            {
                printf("There are no passengers available on this flight.\n");
            }
            else
            {
                // **Step 5: If passengers are found, display the passenger list**
                struct Passenger *temp1 = temp->passengerListHead; // Temporary pointer to traverse the passenger list
                printf("Passenger List for Flight %d:\n", flightNum);
                printf("-----------------------------------\n");

                // **Step 6: Display details of each passenger**
                while (temp1 != NULL)
                {
                    printf("Passenger's Name: %s\n", temp1->name);              // Print passenger's name
                    printf("Passenger's ID: %d\n", temp1->id);                  // Print passenger's ID
                    printf("Passenger's Seat Number: %d\n", temp1->seatNumber); // Print passenger's seat number
                    printf("-----------------------------------\n");

                    temp1 = temp1->next; // Move to the next passenger in the list
                }
                printf("End of the Passenger List.\n"); // End of the list
            }
            return; // Return after displaying the passenger list
        }
        temp = temp->next; // Move to the next flight in the list
    }

    // **Step 7: If the flight is not found**
    if (!flightFound)
    {
        printf("The flight with flight number %d doesn't exist.\n", flightNum); // Display message if the flight is not found
    }
}