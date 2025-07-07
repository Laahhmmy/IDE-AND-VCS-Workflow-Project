// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip> // For std::setprecision and std::showpoint
using namespace std;
int main() {
	cout << "What is the weight of the package in kilograms? ";
	double weight;
	cin >> weight;

	if (weight <= 0) {
		cout << "Invalid weight. Please enter a non-negative value." << endl;
		return 1; // Exit with an error code
	} else if (weight > 20) {
		cout << "Invalid weight. The maximum weight for a package is 20 kilograms." << endl;
		return 1; // Exit with an error code
	}
	cout << "What is the distance to be shipped in kilometers? ";
	double distance;
	cin >> distance;
	if (distance < 10 || distance > 3000) {
		cout << "Invalid distance. The company's minumun and maximum shipping distances are between 10 and 3000 kilometers." << endl;
		return 1; // Exit with an error code
	}
	cout << fixed << setprecision(2) << showpoint;
	if (weight <= 2) {
		cout << "It will cost $" << distance / 500 * 1.10;
	} else if (weight > 2 || weight <= 6) {
		cout << "It will cost $" << distance / 500 * 2.20;
	} else if (weight >6 || weight <= 10) {
		cout << "It will cost $" << distance / 500 * 3.70;
	} else if (weight > 10 || weight <= 20) {
		cout << "It will cost $" << distance / 500 * 4.80;
	}
	return 0;
}