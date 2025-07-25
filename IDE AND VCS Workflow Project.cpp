// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// This program collects information about automobile accidents in different regions and determines which region has the lowest number of accidents.
#include <iostream>
#include <string>
using namespace std;

void getRegInfo(string&, int&); // Function to get region information
bool isLower(int, int); // Function to compare accident numbers
void showLowest(const string&, int); // Function to display the region with the lowest number of accidents


int main() {
	string region, lowRegion; // Variables to hold the current region and the one with the lowest accidents
	int accidents, lowAccidents; // Variables to hold the number of accidents in the current region and the lowest found so far
	getRegInfo(region, accidents); // Get information for the first region
	lowRegion = region; // Initialize with the first region
	lowAccidents = accidents; // Initialize with the first number of accidents
	for (int n = 1; n < 5; n++) { // Loop for 4 more regions
		getRegInfo(region, accidents);
		if (isLower(accidents, lowAccidents)) { // Look for a lower number of accidents
			lowRegion = region;
			lowAccidents = accidents;
		}
	}
	showLowest(lowRegion, lowAccidents); // Display the region with the lowest number of accidents
}

void getRegInfo(string& name, int& accidents) {
	cout << "Enter the region name: ";
	cin >> name;
	do {
		cout << "Enter the number of accidents in the region: ";
		cin >> accidents;
		if (accidents < 0) {
			cout << "Number of accidents cannot be negative. Please try again." << endl;
		}
	} while (accidents < 0);
}

bool isLower(int value1, int value2) { // Function to compare two accident numbers returns true if value1 < value 2
	return (value1 < value2);
}
void showLowest(const string& name, int accidents) {
	cout << "The region with the lowest number of accidents is: " << name << " with " << accidents << " accident(s)." << endl;
}