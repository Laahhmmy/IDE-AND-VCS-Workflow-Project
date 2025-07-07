// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main() {
	cout << "Enter a month (1-12): " << endl;
	int month;
	cin >> month;
	if (month < 1 || month > 12) {
		cout << "Invalid month. Please enter a number between 1 and 12." << endl;
		return 1; // Exit with an error code
	}
	
	cout << "Enter a year: " << endl;
	int year;
	cin >> year;
	if (year < 1) {
		cout << "Invalid year. Please enter a positive number." << endl;
		return 1; // Exit with an error code
	}
	
	
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		cout << "31 days" << endl; // Months with 31 days
		return 0; // Exit successfully
	} else if (month == 4 || month == 6 || month == 9 || month == 11) {
		cout << "30 days" << endl; // Months with 30 days
		return 0; // Exit successfully
	}

	if ((year % 100 == 0 && year % 400 == 0) && month == 2) { 
		cout << "29 days" << endl;
	} else if ((year % 4 == 0 && year % 100 != 0) && month == 2) { 
		cout << "29 days" << endl;
	} else if (month == 2) {
		cout << "28 days" << endl;
	}
	return 0; 
}