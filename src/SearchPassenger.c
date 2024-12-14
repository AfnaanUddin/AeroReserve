#include "../include/headerAeroReserve.h"

// Function to search for a passenger on a specific flight by passenger ID
void SearchPassenger(struct Flight *head)
{
    // **Step 1: Check if there are any flights available**
    if (head == NULL)
    {
        printf("There are no Flights Available so You can't search for A Passenger:\n");
        return; // Return if there are no flights to search
    }

    int flightNum; // Variable to store the flight number entered by the user

    // **Step 2: Prompt the user to enter the flight number to search for a passenger**
    printf("Enter a Flight Number in which you want to search for a Passenger:\n");
    scanf("%d", &flightNum); // Read the flight number from the user

    int flightFound = 0;        // Flag to indicate if the flight was found
    struct Flight *temp = head; // Temporary pointer to traverse the flight list

    // **Step 3: Traverse the flight list to find the flight with the given number**
    while (temp != NULL)
    {
        // **Step 4: Check if the current flight matches the entered flight number**
        if (flightNum == temp->flightNumber)
        {
            flightFound = 1; // Set the flag to indicate the flight was found

            // **Step 5: Check if the flight has passengers**
            if (temp->passengerListHead == NULL)
            {
                printf("There are no passenger's available on the flight number %d:\n", flightNum);
                return; // Return if there are no passengers on the flight
            }

            int pId; // Variable to store the passenger ID entered by the user

            // **Step 6: Prompt the user to enter the passenger ID they want to search for**
            printf("Enter the Id of the passenger you want to search:\n");
            scanf("%d", &pId); // Read the passenger ID from the user

            struct Passenger *temp1 = temp->passengerListHead; // Temporary pointer to traverse the passenger list
            int passengerFound = 0;                            // Flag to indicate if the passenger was found

            // **Step 7: Traverse the passenger list to find the passenger with the given ID**
            while (temp1 != NULL)
            {
                // **Step 8: Check if the current passenger matches the entered ID**
                if (pId == temp1->id)
                {
                    passengerFound = 1; // Set the flag to indicate the passenger was found
                    printf("The Passenger's detail was Found and the details are as shown Below:\n\n");

                    // **Step 9: Print the details of the found passenger**
                    printf("Passenger's Name: %s\n", temp1->name);
                    printf("Passenger's Id: %d\n", temp1->id);
                    printf("Passenger's Seat Number: %d\n", temp1->seatNumber);
                }

                temp1 = temp1->next; // Move to the next passenger in the list
            }

            // **Step 10: If the passenger wasn't found, ask the user if they want to search again**
            if (!passengerFound)
            {
                printf("Passenger with Id %d wasn't found on flight number %d.\n", pId, flightNum);
                char choice; // Variable to store the user's choice for retrying
                printf("Do you want to search for another passenger? (Y/N): ");
                scanf(" %c", &choice); // Include space before %c to consume any leftover newline

                // **Step 11: If the user chooses 'Y' or 'y', call the function recursively to search again**
                if (choice == 'Y' || choice == 'y')
                {
                    SearchPassenger(head); // Call the function again for retry
                }
            }
        }

        temp = temp->next; // Move to the next flight in the list
    }

    // **Step 12: If the flight wasn't found, display a message indicating so**
    if (!flightFound)
    {
        printf("Flight with flight number %d wasn't found:\n", flightNum);
    }
}