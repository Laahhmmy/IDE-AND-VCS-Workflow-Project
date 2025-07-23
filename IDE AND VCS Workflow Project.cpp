// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

void getRegInfo(string&, int&);
bool isLower(int, int);
void showLowest(const string&, int);


int main() {
	string region, lowRegion;
	int accidents, lowAccidents;
	getRegInfo(region, accidents);
	lowRegion = region; // Initialize with the first region
	lowAccidents = accidents; // Initialize with the first number of accidents
	for (int n = 1; n < 5; n++) { // Loop for 4 more regions
		getRegInfo(region, accidents);
		if (isLower(accidents, lowAccidents)) {
			lowRegion = region;
			lowAccidents = accidents;
		}
	}
	showLowest(lowRegion, lowAccidents);
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

bool isLower(int value1, int value2) {
	return (value1 <= value2);
}
void showLowest(const string& name, int accidents) {
	cout << "The region with the lowest number of accidents is: " << name << " with " << accidents << " accidents." << endl;
}