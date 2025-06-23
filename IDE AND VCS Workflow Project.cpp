// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main() {
	double highway = 28.9;
	double town = 23.5;
	double gallons = 20;
	double distanceHighway, distanceTown;
	distanceHighway = gallons * highway;
	distanceTown = gallons * town;
	cout << "The distance the car can travel in the town is " << distanceTown << " miles." << endl;
	cout << "The distance the car can travel on the highway is " << distanceHighway << " miles." << endl;

	return 0;
}