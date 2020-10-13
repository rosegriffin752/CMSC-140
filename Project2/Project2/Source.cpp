/*
 * Class: CMSC140 CRN 21708
 * Instructor: Professor Justh
 * Project #2
 * Description: Converts Metric units to Imperial.
 * Due Date: Friday, October 11, 2019
 * I pledge that I have completed the programming assignment independently.
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Rose Griffin
*/

#include <iostream>
#include <iomanip>
#include <String>

using namespace std;

int main() {

	string countryName; //Holds the name of the user's country
	int menuOption; //Holds what menu option the user chooses.

	int temperature; //Holds the temperature
	double distance; //Holds the distance
	double weight; //Holds the weight

	const double MILES_PER_KILOMETERS = 0.6; //Amount of Miles in one Kilometer
	const double POUNDS_PER_KILOGRAMS = 2.2; //Amount of Pounds in one Kilogram

	//Display title and prompt for country name
	cout << "WORLD WIDE CONVERSIONS \n\nEnter a country name: ";
	getline(cin, countryName);

	//Display menu and prompt for menu option
	cout << "\nConverter Toolkit\n----------------------------------------\n"
		 << "1. Temperature converter\n"
		 << "2. Distance converter\n"
		 << "3. Weight Converter\n"
		 << "4. Quit\n\n"
		 << "Enter your choice (1 - 4) ";
	cin >> menuOption;

	switch (menuOption) {
		case 1: 
			cout << "Please enter a temperature in Celsius (such as 24): "; //Prompt user for Celcius
			cin >> temperature;
			temperature = round((1.8) * (static_cast<double>(temperature)) + 32); //Convert Celcius to Fahrenheit and round to a whole number
			cout << "It is " << temperature << " degrees Fahrenheit. \n\n"; //Display Fahrenheit
			break;
		case 2:
			cout << "Please enter a distance in Kilometers (such as 18.54) "; //Prompt user for Kilometers
			cin >> distance;
			if (distance >= 0) { //Check if distance is not negative.
				distance *= MILES_PER_KILOMETERS; //Convert Kilometers to Miles
				cout << "It is " << showpoint << fixed << setprecision(2) << distance << " miles. \n\n"; //Display Miles
			} else {
				cout << "!!! Program does not convert negative distance !!!\n\n"; //Display error message
			}
			break;
		case 3:
			cout << "Please enter a distance in Kilograms (such as 50.2) "; //Prompt user for Kilograms
			cin >> weight;
			if (weight >= 0) { //Check if weight is not negative
				weight *= POUNDS_PER_KILOGRAMS; //Convert Kilograms to Pounds
				cout << "It is " << showpoint << fixed << setprecision(1) << weight << " pounds. \n\n"; //Display Pounds
			} else {
				cout << "!!! Program does not convert negative weight !!!\n\n"; //Display error message
			}
			break;
		case 4: 
			cout << "You chose to quit the program. \n\n"; //Display quitting program
			break;
		default: 
			cout << "Invalid menu option. Must be (1 - 4) \n\n"; //Display error message
	}

	//Display wrap up
	cout << countryName << " sounds fun!\n\n"
		 << "Thank you for testing my program!\n"
		 << "PROGRAMMER: Rose Griffin\n"
		 << "CMSC140 Project 2\n"
		 << "Due Date: October 11, 2019\n\n";

	system("pause");
	return 0;
}