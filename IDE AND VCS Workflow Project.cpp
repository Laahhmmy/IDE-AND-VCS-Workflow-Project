// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int getRooms();
int getRooms() {
	cout << "How many rooms are there? ";
	int rooms;
	cin >> rooms;
	if (rooms < 1) {
		cout << "Invalid number of rooms. Please enter a positive integer." << endl;
		return getRooms(); // Recursive call for valid input
	}
	else {
		return rooms;

	}
}
double getSqFt(int roonNumber);
double getSqFt(int roonNumber) {
	cout << "How many square feet of wall space in room number " << roonNumber << "? ";
	double wallSpace;
	cin >> wallSpace;
	while (wallSpace <= 0) {
		cout << "Invalid square footage. Please enter a positive number." << endl;
		cin >> wallSpace; // Prompt again for valid input
	}
	return wallSpace; // Return the valid square footage
}
double getPricePerGallon(int roomNumber);
double getPricePerGallon(int roomNumber) {
	cout << "What is the cost of paint per gallon in room number " << roomNumber << "? ";
	double costPerGallon;
	cin >> costPerGallon;
	while (costPerGallon < 10) {
		cout << "Invalid cost. Please enter a number that is 10 or higher." << endl;
		cin >> costPerGallon; // Prompt again for valid input
	}
	return costPerGallon;
}
double getGallonsPerRoom (double squareFeet) {
	const double gallonsPerSquareFoot = 1 / 110; // 1 gallon covers 110 square feet
	return squareFeet * gallonsPerSquareFoot;
}
void displayEstimate(double gallonsNeeded, double paintCharge, double laborHours, double laborCharge) {
	cout << "Gallons of paint to purchase: " << gallonsNeeded << endl;
	cout << "Number of hours of labor: " << laborHours << endl;
	cout << "Cost off paint: " << paintCharge << endl;
	cout << "Cost of labor: " << laborCharge << endl;
	cout << "Total cost of the job: " << paintCharge + laborCharge << endl;
}

double gallonsForRoom(double squareFeet) {
	const double gallonsPerSquareFoot = 1 / 110; // 1 gallon covers 110 square feet
	return squareFeet * gallonsPerSquareFoot;
}
int main() {
	const double gallonsPerSquareFoot = 1 / 110;
	const double laborPerSquareFoot = 8 / 110;
	const double LaborChargePerHour = 25.00;
	double paintCharge = 0, laborCharge = 0, gallonsNeeded = 0, laborHours = 0;
	int rooms = getRooms(); // Get the number of rooms
	for (int i = 1; i <= rooms; i++) {
		double squareFeet = getSqFt(i); // Get square footage for each room
		double costPerGallon = getPricePerGallon(i); // Get cost per gallon for each room
		gallonsNeeded += gallonsForRoom(squareFeet); // Calculate total gallons needed
		paintCharge += costPerGallon * gallonsForRoom(squareFeet); // Calculate total paint charge
		laborHours += squareFeet * laborPerSquareFoot; // Calculate total labor hours
		laborCharge += laborHours * LaborChargePerHour; // Calculate total labor charge
	}
	displayEstimate(gallonsNeeded, paintCharge, laborHours, laborCharge); // Display the estimate
	return 0;
}