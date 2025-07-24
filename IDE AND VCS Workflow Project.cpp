// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip> // for std::setprecision and std::showpoint
using namespace std;

double getCelsius(double);

int main() {
	double celsius;
	cout << fixed << setprecision(1) << showpoint;
	cout << "Celsius Temperature Table Conversion" << endl;
	cout << "Fahrenheit     Celsius" << endl;
	for (int i = 0; i <= 20; i++) {
			celsius = getCelsius(i);
			cout << setw(5) << i << setw(16) << celsius << endl;
	}
	cout << endl;
	return 0;
}

double getCelsius(double fahrenheit) {
	return (fahrenheit - 32) * 5.0 / 9.0;
}