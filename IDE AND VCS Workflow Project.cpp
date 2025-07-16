// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// This program generates a random number between 0 and 100 and prompts the user to guess it.
#include <iostream>
#include <random>
using namespace std;
int main() {
	int randomNumber;
	int number;
	int attempts = 0;
	random_device rd;
	mt19937 gen(rd()); // Initialize random number generator with a random seed
	uniform_int_distribution<> dist(0, 100);
	randomNumber = dist(gen); // Generate a random number between 0 and 100
	do { cout << "Guess a random number between 0 and 100: ";
		cin >> number;
		attempts++;
		if (number == randomNumber) {
			cout << "Congrats you guessed the correct number" << endl;
			cout << "It took you " << attempts << " attempts to guess the number." << endl;
			cout << "The random number was: " << randomNumber << endl;
		}
		else if (number > randomNumber) {
			cout << "Too high, try again." << endl;
		}
		else if (number < randomNumber) {
			cout << "Too low, try again." << endl;
	
		}
		else {
			cout << "Invalid input, please enter a number between 0 and 100." << endl;
		}
		
		} while (number != randomNumber);
	

}