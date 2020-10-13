/*
 * Class: CMSC140 CRN 21708
 * Instructor: Professor Justh
 * Project #3
 * Description: Calculates the occupancy rate and the total hotel income for one night
 * Due Date: November 1, 2019
 * I pledge that I have completed the programming assignment independently.
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Rose Griffin
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main() {

	const int MIN_FLOORS = 1; //Minimum amount of floors
	const int MIN_ROOMS = 1; //Minimum amount of rooms
	const int MAX_FLOORS = 5; //Maximum amount of floors
	const int MAX_ROOMS = 30; //Maximum amount of rooms
	const double SINGLE_PRICE = 60.00; //Rate for single room
	const double DOUBLE_PRICE = 75.00; //Rate for double room
	const double KING_PRICE = 100.00; //Rate for king room
	const double SUITE_PRICE = 150.00; //Rate for suite room

	string locationOfHotel; //Name of the hotel's location
	int numOfFloors = 0; //Number of floors 
	int numOfRooms = 0; //Number of rooms
	int numOfSingle = 0; //Number of single rooms
	int numOfDouble = 0; //Number of double rooms
	int numOfKing = 0; //Number of king rooms
	int numOfSuite = 0; //number of suite rooms

	int roomsOccupied = 0; //Number of occupied rooms
	int totalRooms = 0; //Number of total rooms
	int roomsUnoccupied = 0; //Number of unoccupied rooms
	int floorLeastRooms = 0; //Floor number of the floor with the least rooms
	int numLeastRooms = 0; //The amount of floors on the floor with the least rooms
	double occupancyRate = 0; //Rate of hotel occupancy
	double hotelIncome = 0; //Income of hotel per night

	cout << "========================================================================================================"
		<< "\n\t\t\t\t\t\tBlueMont Hotel\n"
		<< "========================================================================================================\n"
		<< "Enter the location of this hotel chain: ";
	getline(cin, locationOfHotel);

	//Prompt and validate for number of floors
	cout << "Enter the total number of floors in this hotel: ";
	cin >> numOfFloors;
	while (!(numOfFloors <= MAX_FLOORS && numOfFloors >= MIN_FLOORS)) {
		cout << "Number of floors should be between " << MIN_FLOORS << " and " << MAX_FLOORS << ". Please try again!\n\n"
			<< "Enter the total number of floors in this hotel: ";
		cin >> numOfFloors;
	}

	//Prompt and validate for number of rooms per floor
	int tempLeastRooms = 999;
	for (int i = MIN_FLOORS; i <= numOfFloors; i++) {
		cout << "\n\nEnter the total number of rooms on floor " << i << ": ";
		cin >> numOfRooms;
		while (!(numOfRooms <= MAX_ROOMS && numOfRooms >= MIN_ROOMS)) {
			cout << "Number of rooms should be between " << MIN_ROOMS << " and " << MAX_ROOMS << ". Please try again!\n\n"
				<< "Enter the total number of rooms on floor " << i << " ";
			cin >> numOfRooms;
		}
		int tempTotal = -999;
		while (tempTotal == -999) {
			int temp;
			tempTotal = 0;
			cout << "How many SINGLE rooms are occupied on floor " << i << " ? ";
			cin >> temp;
			numOfSingle += temp;
			tempTotal += temp;

			cout << "How many DOUBLE rooms are occupied on floor " << i << " ? ";
			cin >> temp;
			numOfDouble += temp;
			tempTotal += temp;

			cout << "How many KING rooms are occupied on floor " << i << " ? ";
			cin >> temp;
			numOfKing += temp;
			tempTotal += temp;

			cout << "How many SUITE rooms are occupied on floor " << i << " ? ";
			cin >> temp;
			numOfSuite += temp;
			tempTotal += temp;

			if (tempTotal > numOfRooms) {
				cout << "Total number of occupied rooms exceeds the total number of rooms on this floor. Please try again!! \n\n";
				cout << "\n\n";
				cout << "Enter the total number of rooms on floor " << i << ": ";
				cin >> numOfRooms;
				while (!(numOfRooms <= MAX_ROOMS && numOfRooms >= MIN_ROOMS)) {
					cout << "Number of rooms should be between " << MIN_ROOMS << " and " << MAX_ROOMS << ". Please try again!\n\n"
						<< "Enter the total number of rooms on floor " << i << " ";
					cin >> numOfRooms;
				}
				tempTotal = -999;
				numOfSingle = 0;
				numOfDouble = 0;
				numOfKing = 0;
				numOfSuite = 0;
			}
			else {
				roomsOccupied += tempTotal;
			}
			if (numOfRooms < tempLeastRooms) {
				tempLeastRooms = numOfRooms;
				numLeastRooms = numOfRooms;
				floorLeastRooms = i;
			}

		}
		totalRooms += numOfRooms;
	}

	//Perform calculations
	hotelIncome = (numOfSingle * SINGLE_PRICE) + (numOfDouble * DOUBLE_PRICE) + (numOfKing * KING_PRICE) + (numOfSuite * SUITE_PRICE);
	roomsUnoccupied = totalRooms - roomsOccupied;
	occupancyRate = (static_cast<double>(roomsOccupied) / totalRooms) * 100;

	//Display calculations
	cout << "\n\n========================================================================================================"
		<< "\n\t\t\tBlueMont Hotel located at " << locationOfHotel
		<< "\n========================================================================================================"
		<< "\n\t\t   Today's Room Rates (Us$/night) " << "\n\t Single Room \t Double Room \t King Room \t Suite Room"
		<< "\n\t\t " << SINGLE_PRICE << "\t\t" << DOUBLE_PRICE << "\t    " << KING_PRICE << "\t\t     " << SUITE_PRICE << "\n========================================================================================================"
		<< "\n\t\tHotel Income :\t\t\t$" << hotelIncome
		<< "\n\t    Total # of Rooms :\t\t\t" << totalRooms
		<< "\n   Total # of Occupied Rooms :\t\t\t" << roomsOccupied
		<< "\n Total # of Unoccupied Rooms :\t\t\t" << roomsUnoccupied
		<< "\n\t      Occupancy Rate :\t\t     " << fixed << showpoint << setprecision(2) << occupancyRate << "%";

	cout << "\n\nfloor " << floorLeastRooms << " with " << numLeastRooms << " rooms has the least # of rooms.\n";
	if (occupancyRate < 60) {
		cout << "Need to improve Hotel occupancy rate!!\n";
	}

	cout << "\nThank you for testing my program!\nPROGRAMMER: Rose Griffin\nCMSC140 Common Project 3\nDue Date: November 1, 2019\n";
	system("pause");
	return 0;
}