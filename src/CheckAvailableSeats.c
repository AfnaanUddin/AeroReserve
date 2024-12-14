#include "../include/headerAeroReserve.h"

void CheckAvailableSeats(struct Flight *head)
{
    // **Step 1: Check if there are any flights in the system**
    if (head == NULL)
    {
        printf("There Are No Flights Available:\n"); // If no flights exist, print an error message
        return;                                      // Exit the function without performing any further actions
    }

    int flightNum;              // Variable to store the flight number entered by the user
    int flightFound = 0;        // Flag to check if the flight with the entered flight number is found
    struct Flight *temp = head; // Temporary pointer to traverse through the flight list

    // **Step 2: Get flight number input from the user**
    printf("Enter the Flight Number Whose Available Seats You Want To Check:\n");
    scanf("%d", &flightNum); // Read the flight number input by the user

    // **Step 3: Traverse the flight list to find the matching flight number**
    while (temp != NULL)
    {
        // **Step 4: If a flight with the entered number is found**
        if (flightNum == temp->flightNumber)
        {
            flightFound = 1; // Set the flightFound flag to 1, indicating that the flight was found

            // **Step 5: Display the number of available seats in the flight**
            printf("The Number of Available Seats in Flight Number %d is %d:\n", flightNum, temp->availableSeats);
            return; // Exit the function since the available seats have been printed
        }

        // **Step 6: Move to the next flight in the list if the current flight does not match**
        temp = temp->next; // Update the temp pointer to the next flight in the list
    }

    // **Step 7: If no matching flight is found, display an error message**
    if (!flightFound)
    {
        printf("The Flight With Flight Number %d doesn't Exist:\n", flightNum); // Inform the user that the flight was not found
    }
}