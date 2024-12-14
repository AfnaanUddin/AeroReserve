#include "../include/headerAeroReserve.h"

struct Flight *AddPassenger(struct Flight *head)
{
    // **Step 1: Check if there are any flights in the system**
    if (head == NULL)
    {
        printf("There Are No Flights Available:\n");
        return head; // Return the original head (no change) as there are no flights to add a passenger to
    }

    int flightNum;       // Variable to store the flight number entered by the user
    int flightFound = 0; // Flag to indicate if the flight with the given number is found
    char tempName[100];  // Temporary variable to store the passenger's name

    // **Step 2: Get flight number input from the user**
    printf("Enter The Flight Number On Which You Want To Add A Passenger on:\n");
    scanf("%d", &flightNum); // Read the flight number
    getchar();               // Clear the newline character from the input buffer

    struct Flight *temp = head; // Temporary pointer to traverse the list of flights

    // **Step 3: Traverse the list of flights to find the one with the given flight number**
    while (temp != NULL)
    {
        if (flightNum == temp->flightNumber) // Check if current flight's flight number matches the input flight number
        {
            flightFound = 1; // Set the flag to indicate that the flight is found

            // **Step 4: Check if there are available seats on this flight**
            if (temp->availableSeats <= 0)
            {
                printf("No available seats on this flight.\n");
                return head; // Return the original head if no seats are available
            }

            // **Step 5: Allocate memory for the new passenger**
            struct Passenger *newPassenger = (struct Passenger *)malloc(sizeof(struct Passenger));
            if (newPassenger == NULL) // Check if memory allocation failed
            {
                printf("Memory Allocation Failed:\n");
                return head; // Return without adding a passenger in case of memory allocation failure
            }

            // **Step 6: Get and store the passenger's unique ID**
            printf("Enter Passenger's Id:\n");
            scanf("%d", &newPassenger->id);
            getchar(); // Clear the newline character from the input buffer

            // **Step 7: Check for duplicate passenger ID in the flight's passenger list**
            struct Passenger *currentPassenger = temp->passengerListHead;
            while (currentPassenger != NULL)
            {
                if (currentPassenger->id == newPassenger->id) // Check if the ID already exists in the passenger list
                {
                    printf("Passenger ID already exists. Please enter a unique ID.\n");
                    free(newPassenger); // Free the allocated memory since the ID is a duplicate
                    return head;        // Return without adding the passenger
                }
                currentPassenger = currentPassenger->next; // Move to the next passenger in the list
            }

            // **Step 8: Get and store the passenger's name**
            printf("Enter Passenger's Name:\n");
            fgets(tempName, sizeof(tempName), stdin); // Read the passenger's name (can include spaces)

            // Remove the newline character from the end of the string if it's present
            size_t len = strlen(tempName);
            if (len > 0 && tempName[len - 1] == '\n')
            {
                tempName[len - 1] = '\0'; // Replace the newline with a null terminator to properly terminate the string
            }
            strcpy(newPassenger->name, tempName); // Copy the name to the new passenger's name field

            // **Step 9: Get and store the seat number for the passenger**
            printf("Enter Passenger's Seat Number:\n");
            scanf("%d", &newPassenger->seatNumber); // Read the seat number

            // **Step 10: Validate the seat number entered by the user**
            if (newPassenger->seatNumber > 0 && newPassenger->seatNumber <= temp->totalSeats)
            {
                // **Case 1: If there are no passengers on the flight, this passenger becomes the head and tail**
                if (temp->passengerListHead == NULL)
                {
                    temp->passengerListHead = temp->passengerListTail = newPassenger; // Set both head and tail to the new passenger
                    newPassenger->prev = newPassenger->next = NULL;                   // New passenger has no previous or next passengers
                }
                else
                {
                    // **Case 2: Add the new passenger at the end of the passenger list**
                    newPassenger->prev = temp->passengerListTail; // Set the previous passenger (tail) for the new passenger
                    newPassenger->next = NULL;                    // New passenger is the last, so next is NULL
                    temp->passengerListTail->next = newPassenger; // Update the old tail's next to point to the new passenger
                    temp->passengerListTail = newPassenger;       // Update the tail to be the new passenger
                }

                // **Step 11: Decrement the number of available seats on the flight**
                temp->availableSeats--; // Reduce the available seats count for the flight

                // **Step 12: Print a success message for the user**
                printf("Passenger %s (ID: %d) added successfully.\n", newPassenger->name, newPassenger->id);
            }
            else
            {
                // **Invalid Seat Number: Free the passenger node and display an error message**
                printf("Invalid Seat Number. Seat number must be greater than 0 and less than equal to %d.\n", temp->totalSeats);
                free(newPassenger); // Free the memory as the passenger could not be added
            }
            return head; // Return the updated flight list head
        }
        temp = temp->next; // Move to the next flight in the list if the current flight does not match
    }

    // **Step 13: If the flight was not found, print a message**
    if (!flightFound)
    {
        printf("Flight Doesn't Exist:\n");
    }

    return head; // Return the flight list head (unchanged if no passenger was added)
}