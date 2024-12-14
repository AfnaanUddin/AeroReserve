AeroReserve: Flight Reservation System

Project Overview

AeroReserve is a comprehensive flight reservation system built in C programming, utilizing advanced data structures and algorithms to simulate real-world flight management operations. This system handles flight bookings, passenger details, seat allocations, and sorting operations while providing an intuitive command-line interface (CLI) for users. The application is designed to manage flights, passengers, and their information efficiently using linked lists and doubly linked lists.

This project demonstrates my proficiency in C programming, data structures, and problem-solving, as well as my ability to develop scalable solutions to manage complex systems. It is ideal for anyone looking to implement a robust flight reservation system or manage similar large-scale data sets.

Key Features
	•	Flight Management:
	•	Add new flights with relevant details such as flight number, seat count, etc.
	•	View all available flights in the system.
	•	Sort flights based on specific parameters such as flight number.
	•	Passenger Management:
	•	Add, update, and remove passengers from specific flights.
	•	View detailed passenger information (name, seat number, ID).
	•	Sort passengers by seat number using insertion sort.
	•	Data Integrity and Validation:
	•	Real-time validation of input data, such as seat numbers and IDs, ensuring that invalid inputs are handled gracefully.
	•	Ensures passengers are not assigned to invalid or duplicate seats.
	•	Passenger Sorting:
	•	Passengers on a flight are sorted by their seat numbers using the insertion sort algorithm.
	•	Provides a clear and organized view of all passengers.
	•	User-Friendly Interface:
	•	Clear, structured, and informative console outputs guiding users through each operation.
	•	Provides feedback for both successful and failed actions to ensure smooth user experience.

Technologies Used
	•	C Programming Language: Primary language used for implementing the system.
	•	Data Structures:
	•	Linked Lists: For efficient passenger list management.
	•	Doubly Linked Lists: For managing and manipulating the flight-passenger relationship.
	•	Algorithms:
	•	Insertion Sort: For sorting passenger data by seat number.
	•	Input Validation: Ensures that user inputs are valid and that errors are handled gracefully.

Core Functionalities

Flight Operations
	1.	Add Flight: Create new flights by providing necessary details (flight number, seat count).
	2.	View Flight: View a list of all available flights with key details.
	3.	Sort Flights: Sort flights by flight number to organize the flight list.

Passenger Operations
	1.	Add Passenger: Add passengers to specific flights by entering their personal details (name, ID, seat number).
	2.	Update Passenger: Modify details of existing passengers (name, seat number, ID).
	3.	Remove Passenger: Remove passengers from a specific flight.
	4.	View Passenger List: View a detailed list of passengers for a given flight, displaying their names, IDs, and seat numbers.
	5.	Sort Passengers: Sort passengers by seat number using insertion sort for better organization.

Data Flow and Structure
	1.	Flight List: The core structure in the system that holds all flight information, each linked to a list of passengers.
	•	Each flight is represented by a Flight structure containing the flight number, total seat count, and a pointer to a doubly linked list of passengers.
	2.	Passenger List: A doubly linked list within each flight node that stores passenger data.
	•	Each passenger is represented by a Passenger structure containing personal details such as name, ID, and seat number.
	3.	Passenger Sorting: The passengers are sorted by seat number using an insertion sort algorithm to ensure that their information is presented in ascending order.

Compilation and Running Method:
    To compile go to the correct directory and do make.
    To run do ./bin/aeroReserve

Basic Commands and Operations

Once the program is running, the user can interact with the system through the following operations:
	•	Add Flight: Adds a new flight to the system by providing details like flight number and seat count.
	•	View Flights: Displays a list of all flights currently available.
	•	Sort Flights: Sorts and displays flights in order of their flight number.
	•	Add Passenger: Allows adding a new passenger to a specific flight by entering personal details and seat number.
	•	Update Passenger: Modify the details of an existing passenger on a specific flight.
	•	Remove Passenger: Remove a passenger from the flight list.
	•	View Passengers: View the complete list of passengers on a specific flight.
	•	Sort Passengers: Sorts the passengers by seat number for better organization.

Potential Future Enhancements
	•	Database Integration: Integrating with a database system to store flight and passenger data persistently across sessions.
	•	Graphical User Interface (GUI): Developing a GUI using a framework such as GTK or Qt for a more user-friendly experience.
	•	Advanced Sorting Algorithms: Implementing more advanced sorting techniques such as merge sort or quick sort for more efficient data management in larger systems.
	•	Real-time Seat Availability Check: Providing a feature that checks the availability of seats in real-time and prevents double-booking.

Why This Project is Valuable

This project highlights key skills in software development, such as:
	•	Proficiency in C programming and data structures.
	•	Ability to design and implement a complex system with multiple functionalities.
	•	Understanding of memory management, linked lists, and algorithmic thinking.
	•	Strong attention to input validation and error handling, which ensures the stability and reliability of the system.
	•	Clear and concise documentation that guides users through all operations in the system.

Contributions and Acknowledgments

This project was developed independently as part of my efforts to strengthen my programming and problem-solving skills. It incorporates best practices in C programming, data management, and algorithmic design.


Conclusion

AeroReserve serves as a comprehensive and efficient flight reservation system that demonstrates my technical abilities and my approach to solving complex problems with clean, scalable, and efficient code. This project is not only a testament to my skills but also a valuable asset for anyone interested in managing flight data or similar large-scale systems. It is built with a focus on performance, scalability, and usability, ensuring that it can handle a variety of real-world flight and passenger management tasks with ease.