#include "../include/headerAeroReserve.h"

// Save flight and passenger data to a file with improved formatting
void SaveFlights(struct Flight *head)
{
    // **Step 1: Check if the flight list is empty**
    if (head == NULL)
    {
        printf("No flights available to save.\n");
        return; // Return if there are no flights to save
    }

    // **Step 2: Open the file for writing**
    FILE *file = fopen("flights_data.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file for saving.\n");
        return; // Return if the file could not be opened
    }

    // **Step 3: Traverse the flight list to save each flight's details**
    struct Flight *temp = head;
    while (temp != NULL)
    {
        // **Step 4: Save the current flight's basic information (flight number, total seats)**
        fprintf(file, "Flight Number: %d\n", temp->flightNumber);
        fprintf(file, "Total Seats: %d\n", temp->totalSeats);
        fprintf(file, "--------------------------------------\n");

        // **Step 5: Traverse the passenger list of the current flight**
        struct Passenger *pTemp = temp->passengerListHead;
        while (pTemp != NULL)
        {
            // **Step 6: Save each passenger's details (ID, name, seat number)**
            fprintf(file, "Passenger ID: %d\n", pTemp->id);
            fprintf(file, "Name: %s\n", pTemp->name);
            fprintf(file, "Seat Number: %d\n", pTemp->seatNumber);
            fprintf(file, "--------------------------------------\n");

            pTemp = pTemp->next; // Move to the next passenger
        }

        temp = temp->next; // Move to the next flight
    }

    // **Step 7: Close the file after writing all the data**
    fclose(file);

    // **Step 8: Print success message**
    printf("Flight details saved successfully.\n");
}