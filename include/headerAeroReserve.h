#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// **Passenger Structure**
// Represents a passenger on a flight.
// Each passenger has a unique ID, a name, a seat number,
// and pointers to the next and previous passengers to maintain a doubly linked list.
struct Passenger
{
    struct Passenger *prev; // Pointer to the previous passenger in the list
    int id;                 // Unique identifier for the passenger
    char name[100];         // Name of the passenger (max 100 characters)
    int seatNumber;         // Seat number assigned to the passenger
    struct Passenger *next; // Pointer to the next passenger in the list
};

// **Flight Structure**
// Represents a flight in the system.
// Each flight has a unique flight number, destination,
// total and available seats, and a list of passengers.
// It also uses pointers to connect to other flights in the doubly linked list of flights.
struct Flight
{
    struct Flight *prev;                 // Pointer to the previous flight in the list
    int flightNumber;                    // Unique flight number for the flight
    char destination[100];               // Destination of the flight (max 100 characters)
    int totalSeats;                      // Total number of seats available on the flight
    int availableSeats;                  // Number of seats currently available for booking
    struct Passenger *passengerListHead; // Pointer to the head (first) of the passenger list
    struct Passenger *passengerListTail; // Pointer to the tail (last) of the passenger list
    struct Flight *next;                 // Pointer to the next flight in the list
};

// **Function Prototypes**
// Declares the function prototypes for managing flights and passengers

// Creates a new flight and adds it to the list of flights.
struct Flight *addFlight(struct Flight *head);

// Deletes a specific flight from the list of flights.
struct Flight *removeFlight(struct Flight *head);

// Displays the details of all flights in the system.
void DisplayAllFlights(struct Flight *head);

// Searches for a specific flight using its flight number or destination.
void searchFlight(struct Flight *head);

// Saves flight details, including all passengers, to a file.
void SaveFlights(struct Flight *head);

// Adds a passenger to a specific flight.
struct Flight *AddPassenger(struct Flight *head);

// Removes a passenger from a specific flight.
struct Flight *RemovePassenger(struct Flight *head);

// Displays the list of passengers for a given flight.
void ViewPassengerList(struct Flight *head);

// Searches for a specific passenger in a flight using their ID or name.
void SearchPassenger(struct Flight *head);

// Updates the details (like name or seat number) of a specific passenger.
void UpdatePassengerDetails(struct Flight *head);

// Checks and displays the number of available seats on a flight.
void CheckAvailableSeats(struct Flight *head);

// Sorts the passenger list of a specific flight by seat number.
struct Flight *SortPassengerListBySeat(struct Flight *head);

// **Helper Function**
// Swaps two passenger nodes in the passenger list.
// Used for sorting operations like sorting passengers by seat numbers.
void swapPassengerNodes(struct Passenger **passengerListHead, struct Passenger *a, struct Passenger *b);

// Frees all allocated memory and gracefully exits the system.
void ExitSystem(struct Flight *head);