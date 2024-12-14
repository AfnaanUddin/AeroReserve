#include "../include/headerAeroReserve.h"

void UpdatePassengerDetails(struct Flight *head)
{
    // **Step 1: Check if the flight list is empty**
    if (head == NULL)
    {
        printf("There are no flights available, so you can't update any passenger details.\n");
        return; // Return if there are no flights to update
    }

    int flightNum;              // Variable to store the flight number entered by the user
    int flightFound = 0;        // Flag to indicate if the flight with the given flight number is found
    int passengerFound = 0;     // Flag to indicate if the passenger with the given ID is found
    int pId;                    // Variable to store the passenger ID entered by the user
    char tempName[100];         // Temporary buffer to store the updated passenger's name
    struct Flight *temp = head; // Temporary pointer to traverse the flight list

    // **Step 2: Get the flight number from the user**
    printf("Enter the flight number on which you would like to update the details of a passenger:\n");
    scanf("%d", &flightNum); // Read the flight number from the user
    getchar();               // To consume the newline character left by scanf

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
                return; // Return if there are no passengers to update
            }

            // **Step 5: Get the passenger ID to update**
            printf("Enter the ID of the passenger whose details you want to update:\n");
            scanf("%d", &pId); // Read the passenger ID
            getchar();         // To consume the newline character left by scanf

            struct Passenger *temp1 = temp->passengerListHead; // Temporary pointer to traverse the passenger list

            // **Step 6: Search for the passenger with the given ID**
            while (temp1 != NULL)
            {
                if (pId == temp1->id) // Check if the current passenger matches the entered passenger ID
                {
                    passengerFound = 1; // Set the flag indicating the passenger was found

                    // **Step 7: Update the passenger's details**
                    printf("Please enter the new details of the passenger:\n\n");

                    // Update the passenger's name
                    printf("Enter the passenger's name:\n");
                    fgets(tempName, sizeof(tempName), stdin); // Read the updated name
                    size_t len = strlen(tempName);            // Get the length of the input name
                    if (len > 0 && tempName[len - 1] == '\n') // Check if the input contains a newline character
                    {
                        tempName[len - 1] = '\0'; // Remove the newline character
                    }
                    strcpy(temp1->name, tempName); // Update the passenger's name in the list

                    // **Step 8: Validate and update the seat number**
                    printf("Enter the passenger's new seat number:\n");
                    int newSeatNumber;                                          // Variable to store the new seat number
                    scanf("%d", &newSeatNumber);                                // Read the new seat number
                    if (newSeatNumber <= 0 || newSeatNumber > temp->totalSeats) // Validate the seat number
                    {
                        printf("Invalid seat number. Please provide a valid seat number.\n");
                        return; // Return if the seat number is invalid
                    }
                    temp1->seatNumber = newSeatNumber; // Update the passenger's seat number

                    // **Step 9: Optionally, validate and update the passenger's ID (if allowed)**
                    printf("Enter the passenger's new ID (optional):\n");
                    int newId;           // Variable to store the new passenger ID
                    scanf("%d", &newId); // Read the new passenger ID
                    temp1->id = newId;   // Update the passenger's ID

                    printf("Passenger's details updated successfully.\n");
                    return; // Return after updating the passenger details
                }
                temp1 = temp1->next; // Move to the next passenger in the list
            }

            // **Step 10: If the passenger is not found**
            if (!passengerFound)
            {
                printf("The passenger with ID %d was not found on flight %d.\n", pId, flightNum);
                return; // Return if the passenger is not found
            }
        }
        temp = temp->next; // Move to the next flight in the list
    }

    // **Step 11: If the flight is not found**
    if (!flightFound)
    {
        printf("The flight with flight number %d was not found.\n", flightNum); // Display message if the flight is not found
    }
}