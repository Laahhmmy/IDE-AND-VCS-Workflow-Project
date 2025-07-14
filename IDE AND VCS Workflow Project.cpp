// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main() {
	int startingNumber; // Starting number of organisms
	double dailyIncrease; // Daily population increase as a percentage
	cout << "What is the starting number of organisms?\n";
	cin >> startingNumber;
	cout << "What is their daily population increase (as a percentage)?\n";
	cin >> dailyIncrease;
	cout << "How many days will they be allowed to multiply?\n";
	int daysToMultiply; // Number of days to allow multiplication
	cin >> daysToMultiply;
	if (startingNumber < 2 || dailyIncrease < 0 || daysToMultiply < 1) {
		cout << "Invalid input. Please enter a starting number greater than 1, a non-negative daily increase, or a number one or greater for days to multiply" << endl;
		return 1; // Exit with an error code

	}
	double population = startingNumber; // Initialize population with the starting number
	for (int day = 1; day <= daysToMultiply; ++day) {
		population += population * (dailyIncrease / 100.0); // Calculate new population
		cout << "Day " << day << ": " << population << " organisms" << endl; // Output the population for the day
	}
	return 0; // Exit successfully
}