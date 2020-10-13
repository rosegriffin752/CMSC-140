/*
* Class: CMSC140 CRN 21708
* Instructor: Professor Justh
* Project 4
* Description: Calculates average amount of days employees are off
* Due Date: November 22, 2019
* I pledge that I have completed the programming assignment independently.
* I have not copied the code from a student or any source.
* I have not given my code to any student.
* Rose Griffin
*/

#include <iostream> 
#include <iomanip>
#include <fstream>
using namespace std;

int numOfEmployees();
int totDaysAbsent(int, ofstream&);
double averageAbsent(int, int);

int main() {
	ofstream outputFile; //File where information is outputed to
	int numEmployees; //Total number of employees
	int totalDays; //Total days employees were absent
	double averageDaysAbsent; //Average numbers of days employees were absent

	ofstream outfile("employeeAbsences.txt");

	cout << "Calculate the average number of days a company's employees are absent.\n"; //Display title
	numEmployees = numOfEmployees();
	totalDays = totDaysAbsent(numEmployees, outfile);
	averageDaysAbsent = averageAbsent(numEmployees, totalDays);

	//Write information to file
	outfile << "\nThe " << numEmployees << " employees were absent a total of " << totalDays << " days."
		<< "\nThe average number of days absent is " << fixed << showpoint << setprecision(1) << averageDaysAbsent << " days."
		<< "\n\nProgrammer: Rose Griffin";

	cout << "\nDue Date: 11/22/19 \nProgrammer: Rose Griffin\n";

	outfile.close();
	system("pause");
	return 0;
}

/*
* nunOfEmployees prompts the user for the number of employees in the company and checks to see if
* the input is valid. It takes no parameters and returns the number of employees in the company.
*/
int numOfEmployees() {
	int numEmployees = 0;
	while (numEmployees < 1) {
		cout << "\nPlease enter the number of employees in the company: ";
		cin >> numEmployees;
		if (numEmployees < 1) {
			cout << "Invalid number. \n\n";
		}
	}
	return numEmployees;
}

/*
* totDaysAbsent keeps track of how many days each employee has been absent and writes it to the file.
* It takes the two parameters, the number of employees and the file, and returns the total number of days employees were absent.
*/
int totDaysAbsent(int numEmployees, ofstream& outfile) {
	outfile << "EMPLOYEE ABSENCE REPORT"
		<< "\nemployee id " << setw(13) << "days absent" << endl;
	int totalDays = 0; //Calculates the total days absent between all employees
	for (int i = 0; i < numEmployees; i++) {
		int idNum; //Keeps employee ID
		cout << "Please enter an employee ID: ";
		cin >> idNum;
		int daysAbsent = -1; //Keeps the days absent for current employee
		while (daysAbsent < 0) {
			cout << "Please enter number of days this employee was absent: ";
			cin >> daysAbsent;
			if (daysAbsent < 0) {
				cout << "Invalid number.\n";
			}
		}
		outfile << setw(8) << idNum << setw(10) << daysAbsent << endl;
		totalDays += daysAbsent;
	}
	return totalDays;
}

/*
* averageAbsent calculates the average days employees were absent. It takes two parameters: the number of employees and
* the total number of days they were absent. It returns average days employees were absent.
*/
double averageAbsent(int numEmployees, int totalDays) {
	double average = static_cast<double>(totalDays) / numEmployees;
	return average;
}