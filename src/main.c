#include "../include/headerAeroReserve.h"

int main()
{
    // **Step 1: Display a welcome message to the user**
    printf("\n");
    printf("-------------------------------------------------- WELCOME TO AERORESERVE --------------------------------------------------\n\n");

    // **Step 2: Initialize the head of the flight list as NULL (empty list)**
    struct Flight *head = NULL;

    // **Step 3: Declare a variable to store the user's menu choice**
    int choice;

    // **Step 4: Start a do-while loop to display the menu and process user input until the user exits (choice != 15)**
    do
    {
        // **Step 5: Display the menu options to the user**
        printf("MENU:\n\n");
        printf("1. Add A Flight To The System\n");
        printf("2. Add A Passenger To A Flight\n");
        printf("3. Remove A Passenger From A Flight\n");
        printf("4. View The Passenger's List For A Flight\n");
        printf("5. Search For A Passenger In A Flight\n");
        printf("6. Update The Passenger Details Of A Passenger in a Flight\n");
        printf("7. Check Available Seats In A Flight\n");
        printf("8. Sort The Passenger List By Seat Number In A Flight\n");
        printf("9. Display All Flights\n");
        printf("10. Delete a Flight\n");
        printf("11. Find a Flight\n");
        printf("12. Save the Flight on a Text File:\n");
        printf("13. Exit\n");

        // **Step 6: Prompt the user to enter their choice**
        printf("Enter Your Choice: ");
        scanf("%d", &choice); // Read the user's choice

        // **Step 7: Use a switch-case statement to handle the user's choice**
        switch (choice)
        {
        case 1:
            // Add a flight to the system
            head = addFlight(head);
            break;
        case 2:
            // Add a passenger to a flight
            head = AddPassenger(head);
            break;
        case 3:
            // Remove a passenger from a flight
            head = RemovePassenger(head);
            break;
        case 4:
            // View the passenger list for a flight
            ViewPassengerList(head);
            break;
        case 5:
            // Search for a passenger in a flight
            SearchPassenger(head);
            break;
        case 6:
            // Update the details of a passenger in a flight
            UpdatePassengerDetails(head);
            break;
        case 7:
            // Check the available seats in a flight
            CheckAvailableSeats(head);
            break;
        case 8:
            // Sort the passenger list by seat number in a flight
            head = SortPassengerListBySeat(head);
            break;
        case 9:
            // Display all flights
            DisplayAllFlights(head);
            break;
        case 10:
            // Remove a flight from the system
            head = removeFlight(head);
            break;
        case 11:
            // Search for a flight
            searchFlight(head);
            break;
        case 12:
            // Save the flight details to a text file
            SaveFlights(head);
            break;
        case 13:
            // Exit the system and clean up resources
            ExitSystem(head);
            break;
        default:
            // Invalid choice: Prompt the user to enter a valid choice
            printf("Enter a Valid Value between (1 - 15)\n");
            break;
        }
    } while (choice != 15); // Repeat the menu until the user chooses to exit (choice == 15)

    return 0; // Return from the main function (program terminates)
}