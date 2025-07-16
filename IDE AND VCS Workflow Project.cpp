// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
using namespace std;
int main() {
	int randomNumber;
	int number;
	random_device rd;
	mt19937 gen(rd()); // Initialize random number generator with a random seed
	uniform_int_distribution<> dist(0, 100);
	cout << "Guess a random number: ";
	cin >> number;


	if (number == randomNumber) {
		cout << "Congrats you guessed the correct number";
	} 
	else if (number > randomNumber) {
		cout << "Too high, try again.";
		}
	else if (number < randomNumber) {
		cout << "Too low, try again.";
		}
	else {
		cout << "Invalid input, please enter a number between 0 and 100.";
	}

}