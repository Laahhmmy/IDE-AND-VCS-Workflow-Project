// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main() {

	double fiveYears, sevenYears, tenYears;
	double currentOceanLevel = 0;
	fiveYears = currentOceanLevel + 1.5 * 5; // 1.5 mm per year for 5 years
	sevenYears = currentOceanLevel + 1.5 * 7; // 1.5 mm per year for 7 years
	tenYears = currentOceanLevel + 1.5 * 10; // 1.5 mm per year for 10 years
	cout << "The current ocean level is " << currentOceanLevel << " mm." << endl;
	cout << "The ocean level in 5 years will be " << fiveYears << " mm." << endl;
	cout << "The ocean level in 7 years will be " << sevenYears << " mm." << endl;
	cout << "The ocean level in 10 years will be " << tenYears << " mm." << endl;

	return 0;

}