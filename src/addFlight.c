#include "../include/headerAeroReserve.h"

// Function to add a new flight to the system
// The function will allocate memory for a new flight, prompt the user for the details,
// and then add the new flight to the list of flights.
struct Flight *addFlight(struct Flight *head)
{
    // Allocate memory for a new flight node
    struct Flight *newFlight = (struct Flight *)malloc(sizeof(struct Flight));

    // Check if memory allocation was successful
    if (newFlight == NULL)
    {
        // If memory allocation fails, print an error message and return the current head (no changes made)
        printf("Memory Allocation Failed:\n");
        return head;
    }

    // Prompt the user to enter the flight number
    printf("Enter Flight Number:\n");
    scanf("%d", &newFlight->flightNumber); // Read the flight number from the user
    getchar();                             // Clear the newline character from the input buffer to prevent it from interfering with future input

    // Prompt the user to enter the destination of the flight
    printf("Enter Destination:\n");
    fgets(newFlight->destination, sizeof(newFlight->destination), stdin); // Read the destination using fgets to handle spaces

    // Remove the newline character at the end of the string, if present, after reading input
    size_t len = strlen(newFlight->destination);
    if (len > 0 && newFlight->destination[len - 1] == '\n')
    {
        newFlight->destination[len - 1] = '\0'; // Replace newline with null terminator to properly terminate the string
    }

    // Validate that the destination is not empty
    if (strlen(newFlight->destination) == 0)
    {
        // If the destination is empty, print an error message, free the allocated memory, and return the current head
        printf("Destination cannot be empty.\n");
        free(newFlight); // Free the allocated memory for the failed flight creation
        return head;
    }

    // Prompt the user to enter the total number of seats for the flight
    printf("Enter The Total Seats Available:\n");
    scanf("%d", &newFlight->totalSeats); // Read the total seats from the user

    // Validate that the total seats value is positive
    if (newFlight->totalSeats <= 0)
    {
        // If the total seats are not positive, print an error message, free the memory, and return the current head
        printf("Total seats must be a positive number.\n");
        free(newFlight); // Free the allocated memory for the failed flight creation
        return head;
    }

    // Set the available seats to be equal to the total seats initially (all seats are available)
    newFlight->availableSeats = newFlight->totalSeats;

    // Initialize the passenger list as empty
    newFlight->passengerListHead = newFlight->passengerListTail = NULL;

    // Check if the flight list is empty (i.e., the head is NULL)
    if (head == NULL)
    {
        // If the list is empty, make the new flight the head of the list
        head = newFlight;
        newFlight->prev = newFlight->next = NULL; // Set the previous and next pointers to NULL since it's the only flight
    }
    else
    {
        // If the list already contains flights, traverse to the last flight in the list
        struct Flight *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next; // Move to the next flight in the list until the last flight
        }

        // Insert the new flight at the end of the list
        newFlight->next = temp->next; // Set the next pointer of the new flight to NULL (it will be the last flight)
        newFlight->prev = temp;       // Set the previous pointer of the new flight to the last flight in the list
        temp->next = newFlight;       // Set the next pointer of the current last flight to the new flight
    }

    // Print a success message indicating the flight has been created successfully
    printf("Flight with Flight Number %d, Destination %s has been created successfully.\n",
           newFlight->flightNumber, newFlight->destination);

    // Return the head of the flight list (which could have changed if the list was empty)
    return head;
}