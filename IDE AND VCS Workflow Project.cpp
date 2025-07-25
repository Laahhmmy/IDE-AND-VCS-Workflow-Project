// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// This program asks the user for the number of rooms to be painted, the square footage of wall space in each room, and the cost of paint per gallon.
// It then calculates the total gallons of paint needed, the cost of paint, the number of hours of labor required, and the total cost of the job.
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int getRooms();
int getRooms() { // Function to get the number of rooms from the user
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
double getSqFt(int roomNumber);
double getSqFt(int roomNumber) { // Function to get the square footage of wall space in a room
	cout << "How many square feet of wall space in room number " << roomNumber << "? ";
	double wallSpace;
	cin >> wallSpace;
	while (wallSpace <= 0) {
		cout << "Invalid square footage. Please enter a positive number." << endl;
		cin >> wallSpace; // Prompt again for valid input
	}
	return wallSpace; // Return the valid square footage
}
double getPricePerGallon(int roomNumber);
double getPricePerGallon(int roomNumber) { // Function to get the cost of paint per gallon for a room
	cout << "What is the cost of paint per gallon in room number " << roomNumber << "? ";
	double costPerGallon;
	cin >> costPerGallon;
	while (costPerGallon < 10) {
		cout << "Invalid cost. Please enter a number that is 10 or higher." << endl;
		cin >> costPerGallon; // Prompt again for valid input
	}
	return costPerGallon;
}
double getGallonsPerRoom(double squareFeet) { // Function to calculate the gallons of paint needed for a room based on square footage
	const double gallonsPerSquareFoot = 1.0 / 110.0; // 1 gallon covers 110 square feet
	return ceil(squareFeet * gallonsPerSquareFoot); // Use ceil to round up to the nearest whole gallon
}
void displayEstimate(double gallonsNeeded, double paintCharge, double laborHours, double laborCharge) { // Function to display the estimate of the painting job
	cout << fixed << setprecision(2);
	cout << "Gallons of paint to purchase: " << gallonsNeeded << endl;
	cout << "Number of hours of labor: " << laborHours << endl;
	cout << "Cost of paint: " << "$" << paintCharge << endl;
	cout << "Cost of labor: " << "$" << laborCharge << endl;
	cout << "Total cost of the job: " << "$" << paintCharge + laborCharge << endl;
}

int main() { // Main function to execute the program
	const double laborPerSquareFoot = 8.0 / 110.0;
	const double LaborChargePerHour = 25.00;
	double paintCharge = 0, laborCharge = 0, gallonsNeeded = 0, laborHours = 0;
	int rooms = getRooms(); // Get the number of rooms
	for (int n = 1; n <= rooms; n++) {
		double squareFeet = getSqFt(n); // Get square footage for each room
		double costPerGallon = getPricePerGallon(n); // Get cost per gallon for each room
		double gallons = getGallonsPerRoom(squareFeet); // Calculate gallons needed for the room
		double labor = squareFeet * laborPerSquareFoot; // Calculate labor hours for the room
		gallonsNeeded += gallons; // Calculate total gallons needed
		paintCharge += costPerGallon * gallons; // Calculate total paint charge
		laborHours += labor; // Calculate total labor hours
		laborCharge += labor * LaborChargePerHour; // Calculate total labor charge
	}
	cout << endl; 
	cout << "Estimate for Painting " << rooms << " Rooms" << endl;
	displayEstimate(gallonsNeeded, paintCharge, laborHours, laborCharge); // Display the estimate
	return 0;
}