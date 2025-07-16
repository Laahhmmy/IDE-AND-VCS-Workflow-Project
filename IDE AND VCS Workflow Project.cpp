// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// This allows for user to input the starting number of organisms, their daily increase percentage, and the number of days to multiply.
// The program then calculates and displays the population of organisms for each day.

#include <iostream>
using namespace std;
int main() {
	int startingNumber; 
	double dailyIncrease; 
	cout << "What is the starting number of organisms?\n";
	cin >> startingNumber;
	cout << "What is their daily population increase (as a percentage)?\n";
	cin >> dailyIncrease;
	cout << "How many days will they be allowed to multiply?\n";
	int daysToMultiply; 
	cin >> daysToMultiply;
	if (startingNumber < 2 || dailyIncrease < 0 || daysToMultiply < 1) {
		cout << "Invalid input. Please enter a starting number greater than 1, a non-negative daily increase, or a number one or greater for days to multiply" << endl;
		return 1; 

	}
	double population = startingNumber; 
	for (int day = 1; day <= daysToMultiply; ++day) {
		population += population * (dailyIncrease / 100.0); 
		cout << "Day " << day << ": " << population << " organisms" << endl; 
	}
	return 0; 
}