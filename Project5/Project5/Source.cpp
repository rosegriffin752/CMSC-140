/*
 * Class: CMSC140 CRN 21708
 * Instructor: Professor Justh
 * Project #5
 * Description: Determines whether or not the user inputs a Lo Shu Magic Square
 * Due Date: December 13, 2019
 * I pledge that I have completed the programming assignment independently.
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Rose Griffin
 */

#include <iostream>
using namespace std;

#include<iostream>
using namespace std;

// Global constants 
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

// Function prototypes
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);

int main()
{

	int arrayRow1[3], arrayRow2[3], arrayRow3[3];
	bool done = false;
	char option; //Takes in whether or not the user wants to continue

	cout << "\tLO SHU MAGIC SQUARE \n\n";
	while (!done) { //Loops until user inputs 'n'
		fillArray(arrayRow1, arrayRow2, arrayRow3, 3);
		showArray(arrayRow1, arrayRow2, arrayRow3, 3);

		if (isMagicSquare(arrayRow1, arrayRow2, arrayRow3, 3) == true)
			cout << "\nThis is a Lo Shu magic square.\n";
		else
			cout << "\nThis is not a Lo Shu magic square.\n";
		

		cout << "\nDo you want to try again? ";
		cin >> option;
		if (option == 'n')
			done = true;
	}
	cout << "\nProgrammer: Rose Griffin"
		 << "\nProject #5"
		 << "\nDate Due: December 13, 2019\n";
	system("pause");
	return 0;
}

/* 
 * function isMagicSquare takes in four parameters, which include each row of the square and the size,
 * calls other functions to see if the square inputted by the user fits all the criteria for being a Lo shu magic square, and returns
 * if it is true or flase;
 */ 
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
	bool isValid;
	if (!(checkRange(arrayRow1, arrayRow2, arrayRow3, 3, MIN, MAX)))
		isValid = false;
	else if (!(checkUnique(arrayRow1, arrayRow2, arrayRow3, 3)))
		isValid = false;
	else if (!(checkRowSum(arrayRow1, arrayRow2, arrayRow3, 3)))
		isValid = false;
	else if (!(checkColSum(arrayRow1, arrayRow2, arrayRow3, 3)))
		isValid = false;
	else if (!(checkColSum(arrayRow1, arrayRow2, arrayRow3, 3)))
		isValid = false;
	else if (!(checkDiagSum(arrayRow1, arrayRow2, arrayRow3, 3)))
		isValid = false;
	else
		isValid = true;
	return isValid;
}

/*
 * function checkRange takes in six parameters, which include each row of the square, the size, the max, and the min,
 * checks each value in all of the rows to see if they are between the maximum value and the minimum value, and
 * returns true if all values are in range and false if one or more is not.
 */
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max) {
	bool isValid = true;
	for (int i = 1; i < 4; i++) { //Loops for the amount of rows, which will always be 3
		for (int j = 0; j < size; j++) { //Loops for the amount of terms in each row
			if (i == 1)
				arrayRow1[j] > max || arrayRow1[j] < min ? isValid = false : isValid;
			else if (i == 2)
				arrayRow2[j] > max || arrayRow2[j] < min ? isValid = false : isValid;
			else
				arrayRow3[j] > max || arrayRow3[j] < min ? isValid = false : isValid;
		}
	}
	return isValid;
}

/*
 * function checkUnique takes in four parameters, which include each row of the square and the size,
 * checks if each value in all of the rows are unique, and returns true if they are and false if they arent.
 */
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
	bool isValid = true;
	int occurances[9] = { 0,0,0,0,0,0,0,0,0 }; //Each index of this array corresponds with a number between the range. For instance, occurances[0] corresponds with 1
	for (int i = 1; i < 4; i++) { //Loops for the amount of rows, which will always be 3
		for (int j = 0; j < size; j++) { //Loops for the amount of terms in each row
			if (i == 1)
				occurances[arrayRow1[j]-1]++;
			else if (i == 2)
				occurances[arrayRow2[j]-1]++;
			else
				occurances[arrayRow3[j]-1]++;
		}
	}
	for (int i = 0; i < 8; i++)
		occurances[i] > 1 ? isValid = false : isValid;

	return isValid;
}

/*
 * function checkRowSum takes in four parameters, which include each row of the square and the size,
 * adds up all values in each row, and returns true if all sums are equal to each other.
 */
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
	int sumRow1 = arrayRow1[0] + arrayRow2[0] + arrayRow3[0];
	int sumRow2 = arrayRow1[1] + arrayRow2[1] + arrayRow3[1];
	int sumRow3 = arrayRow1[2] + arrayRow2[2] + arrayRow3[2];

	return sumRow1 == sumRow2 && sumRow1 == sumRow3 && sumRow2 == sumRow3;
}

/*
 * function checkColSum takes in four parameters, which include each row of the square and the size,
 * adds up all values in each column, and returns true if all sums are equal to each other.
 */
bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
	int sumCol1 = arrayRow1[0] + arrayRow2[0] + arrayRow3[0];
	int sumCol2 = arrayRow1[1] + arrayRow2[1] + arrayRow3[1];
	int sumCol3 = arrayRow1[2] + arrayRow2[2] + arrayRow3[2];

	return sumCol1 == sumCol2 && sumCol1 == sumCol3 && sumCol2 == sumCol3;
}

/*
 * function checkColSum takes in four parameters, which include each row of the square and the size,
 * adds up all values in each diagonal, and returns true if both sums are equal to each other.
 */
bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
	int sumDiag1 = arrayRow1[0] + arrayRow2[1] + arrayRow3[2]; //Sum of the diagonal from left to right
	int sumDiag2 = arrayRow1[2] + arrayRow2[1] + arrayRow3[0]; //Sum of the diagonal from right to left

	return sumDiag1 == sumDiag2;
}

/*
 * function fillArray takes in four parameters, which include each row of the square and the size,
 * inputs values entered by the user in each row, and does not return anything.
 */
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
	int num;
	for (int i = 1; i < 4; i++) { //Loops for the amount of rows, which will always be 3
		cout << "Enter the three numbers for row " << i << ": ";
		for (int j = 0; j < size; j++) { //Loops for the amount of terms in each row
			cin >> num;
			if (i == 1)
				arrayRow1[j] = num;
			else if (i == 2)
				arrayRow2[j] = num;
			else
				arrayRow3[j] = num;
		}
		cout << "\n";
	}
}

/*
 * function showArray takes in four parameters, which include each row of the square and the size,
 * prints out every value in each row, and does not return anything.
 */
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
	for (int i = 1; i < 4; i++) { //Loops for the amount of rows, which will always be 3
		for (int j = 0; j < size; j++) { //Loops for the amount of terms in each row
			if (i == 1)
				cout << arrayRow1[j] << "  ";
			else if (i == 2)
				cout << arrayRow2[j] << "  ";
			else
				cout << arrayRow3[j] << "  ";
		}
		cout << "\n";
	}
}
