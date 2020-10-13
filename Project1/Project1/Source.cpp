/*
* Class: CMSC140 CRN 21708
* Instructor: Professor Justh
* Project #1
* Description: Converts years to different units of time, and also demonstrates arithmetic in C++
* Due Date: Friday, September 20, 2019 at 11:59pm
* I pledge that I have completed the programming assignment independently.
* I have not copied the code from a student or any source.
* I have not given my code to any student
* Rose Griffin
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

	const string PROGRAMMER_NAME = "Rose Griffin"; //The name of the programmer
	const string DUE_DATE = "9/20/19";// The date when this assignment is due
	const int ASSIGNMENT_NUMBER = 1; // The number of this assignment
	const int ONE_DOG_YEAR = 7; //The amount of dog years in one human year
	const int ONE_GOLD_FISH_YEAR = 5; //The amount of gold fish years in one human year
	const int DAYS_PER_MONTH = 30; //The amount of days per month

	string robotName = "Nao"; //The robot's name
	string visitorName; //User's name
	unsigned int age; //Holds a person's or pet's age
	int num1; //First number
	int num2; //Second number

	unsigned int months; //Age in terms of months
	unsigned int days; //Age in terms of days
	unsigned int hours; //Age in terms of hours
	unsigned int minutes; //Age in terms of minutes
	unsigned int seconds; //Age in terms of seconds
	unsigned int dogAge; //Age in terms of dog years
	unsigned int goldFishAge; //Age in terms of gold fish years
	int sum; //The sum of num1 + num2
	double quotient; //The quotient of num1 / num2

	//Display title
	cout << "**************** Robot Prototype Scripting ********************";

	//Prompt and input name and age
	cout << "\n\nHello, welcome to Montgomery College! My name is " << robotName << ". May I have your name? ";
	getline(cin, visitorName);
	cout << "Nice to have you with us today, " << visitorName << "!\nLet me impress you with a small game.\n"
		 << "Give me the age of an important person or pet to you. \nPlease give me only a number! ";
	cin >> age;

	//Calculate months, days, hours, minutes, seconds, dog age, and fish age.
	months = age * 12;
	days = months * DAYS_PER_MONTH;
	hours = days * 24;
	minutes = hours * 60;
	seconds = minutes * 60;
	dogAge = age * ONE_DOG_YEAR;
	goldFishAge = age * ONE_GOLD_FISH_YEAR;

	//Display calculations
	cout << "\nYou have entered " << age
		 << "\nIf this is for a person, the age can be expressed as: \n"
		 << age << " years\n"
		 << "or " << months << " months\n"
		 << "or about " << days << " days\n"
		 << "or about " << hours << " hours\n"
		 << "or about " << minutes << " minutes\n"
		 << "or about " << seconds << " seconds\n\n"
		 << "If this is for a dog, it is " << dogAge << " years old in human age.\n"
		 << "If this is for a gold fish, it is " << goldFishAge << " years old in human age.\n\n";

	//Prompt and input two numbers
	cout << "Let's play another game, " << visitorName << ". Give me a whole number. ";
	cin >> num1;
	cout << "Very Well. Give me another whole number. ";
	cin >> num2;

	//Calculate sum and quotient
	sum = num1 + num2;
	quotient = static_cast<float>(num1) / (num2);

	//Display calculations
	cout << "Using the operator ' + ' in C++, the result of " << num1 << " + " << num2 << " is " << sum << ". "
		 << "\nUsing the operator ' / ', the result of " << num1 << " / " << num2 << " is " << num1 / num2 << "; "
		 << "\nhowever, the result of " << setprecision(1) << fixed << showpoint << static_cast<double>(num1) << " / " 
		 << setprecision(1) << fixed << showpoint << static_cast<double>(num2) << " is about " 
		 << setprecision(1) << fixed << showpoint << quotient << ". \n";

	//Display wrap up
	cout << "\n\nThank you for testing my program!"
		 << "\nPROGRAMMER: Rose Griffin"
		 << "\nCMSC140 Project " << ASSIGNMENT_NUMBER
		 << "\nDue Date: " << DUE_DATE << "\n";

	system("pause");
	return 0;
}


