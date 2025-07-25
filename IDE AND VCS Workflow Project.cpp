// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// This program creates a table of Fahrenheit to Celsius temperature conversions from 0 to 20 degrees Fahrenheit.
#include <iostream>
#include <iomanip> // for std::setprecision and std::showpoint
using namespace std;

double getCelsius(double); // Function to convert Fahrenheit to Celsius

int main() {
	double celsius;
	cout << fixed << setprecision(1) << showpoint;
	cout << "Celsius Temperature Table Conversion" << endl;
	cout << "Fahrenheit     Celsius" << endl;
	for (int i = 0; i <= 20; i++) { // Loop from 0 to 20 degrees Fahrenheit
			celsius = getCelsius(i);
			cout << setw(5) << i << setw(16) << celsius << endl; // Print Fahrenheit and corresponding Celsius values
	}
	cout << endl;
	return 0;
}

double getCelsius(double fahrenheit) { // Converts Fahrenheit to Celsius and returns the value
	return (fahrenheit - 32) * 5.0 / 9.0;
}