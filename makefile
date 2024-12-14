bin/aeroReserve: AddPassenger.o CheckAvailableSeats.o addFlight.o DisplayAllFlights.o Exit.o removeFlight.o RemovePassenger.o SearchFlight.o SearchPassenger.o SortPassengerList.o UpdatePassengerDetails.o ViewPassenger.o saveFlights.o main.o
	gcc -Wall -std=c99 bin/AddPassenger.o bin/CheckAvailableSeats.o bin/addFlight.o bin/DisplayAllFlights.o bin/Exit.o bin/removeFlight.o bin/RemovePassenger.o bin/SearchFlight.o bin/SearchPassenger.o bin/SortPassengerList.o bin/UpdatePassengerDetails.o bin/ViewPassenger.o bin/saveFlights.o bin/main.o -o bin/aeroReserve

AddPassenger.o: src/AddPassenger.c include/headerAeroReserve.h
	gcc -Wall -std=c99 -c src/AddPassenger.c -o bin/AddPassenger.o

CheckAvailableSeats.o: src/CheckAvailableSeats.c include/headerAeroReserve.h
	gcc -Wall -std=c99 -c src/CheckAvailableSeats.c -o bin/CheckAvailableSeats.o

addFlight.o: src/addFlight.c include/headerAeroReserve.h
	gcc -Wall -std=c99 -c src/addFlight.c -o bin/addFlight.o

DisplayAllFlights.o: src/DisplayAllFlights.c include/headerAeroReserve.h
	gcc -Wall -std=c99 -c src/DisplayAllFlights.c -o bin/DisplayAllFlights.o

Exit.o: src/Exit.c include/headerAeroReserve.h
	gcc -Wall -std=c99 -c src/Exit.c -o bin/Exit.o

removeFlight.o: src/removeFlight.c include/headerAeroReserve.h
	gcc -Wall -std=c99 -c src/removeFlight.c -o bin/removeFlight.o

RemovePassenger.o: src/RemovePassenger.c include/headerAeroReserve.h
	gcc -Wall -std=c99 -c src/RemovePassenger.c -o bin/RemovePassenger.o

SearchFlight.o: src/SearchFlight.c include/headerAeroReserve.h
	gcc -Wall -std=c99 -c src/SearchFlight.c -o bin/SearchFlight.o

SearchPassenger.o: src/SearchPassenger.c include/headerAeroReserve.h
	gcc -Wall -std=c99 -c src/SearchPassenger.c -o bin/SearchPassenger.o

SortPassengerList.o: src/SortPassengerList.c include/headerAeroReserve.h
	gcc -Wall -std=c99 -c src/SortPassengerList.c -o bin/SortPassengerList.o

UpdatePassengerDetails.o: src/UpdatePassengerDetails.c include/headerAeroReserve.h
	gcc -Wall -std=c99 -c src/UpdatePassengerDetails.c -o bin/UpdatePassengerDetails.o

ViewPassenger.o: src/ViewPassenger.c include/headerAeroReserve.h
	gcc -Wall -std=c99 -c src/ViewPassenger.c -o bin/ViewPassenger.o

saveFlights.o: src/saveFlights.c include/headerAeroReserve.h
	gcc -Wall -std=c99 -c src/saveFlights.c -o bin/saveFlights.o

main.o: src/main.c include/headerAeroReserve.h
	gcc -Wall -std=c99 -c src/main.c -o bin/main.o

clean:
	rm bin/*