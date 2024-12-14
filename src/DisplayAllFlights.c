#include "../include/headerAeroReserve.h"

void DisplayAllFlights(struct Flight *head)
{
    // **Step 1: Check if the flight list is empty**
    if (head == NULL)
    {
        printf("There are no flights available.\n"); // If no flights exist, print a message and exit the function
        return;                                      // Return without performing any further actions
    }

    // **Step 2: Print the header with column names**
    printf("%-15s %-15s %-15s %-15s\n", "Flight Number", "Destination", "Total Seats", "Available Seats");
    printf("-------------------------------------------------------------\n"); // Print a separator line for better readability

    // **Step 3: Traverse the flight list**
    struct Flight *temp = head; // Temporary pointer to traverse through the flight list

    // **Step 4: Traverse each flight in the list and print its details**
    while (temp != NULL)
    {
        // Print the flight information in a formatted way
        printf("%-15d %-15s %-15d %-15d\n",
               temp->flightNumber,    // Flight number
               temp->destination,     // Destination of the flight
               temp->totalSeats,      // Total seats available in the flight
               temp->availableSeats); // Available seats on the flight

        temp = temp->next; // Move to the next flight in the list
    }
}