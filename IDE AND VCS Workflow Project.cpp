// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
	const int asterisk = 1000;
	int year = 1900, populationFigure;
	string fileName;
	ifstream infile;
	cout << "Enter the name of the file to read: ";
	cin >> fileName;
	infile.open(fileName);
	if (!infile) {
		cout << "Error opening file: " << fileName << endl;
		return 1; // Exit with error code
	}
	cout << "My Town Population Growth" << endl;
	cout << "Each asterisk (*) represents " << asterisk << " people." << endl;
	while (infile >> populationFigure) {
		if (populationFigure < 0) {
			cout << "Invalid population figure: " << populationFigure << " for year " << year << endl;
			continue; // Skip invalid entries
		}
		cout << year << ": ";
		year += 20; // Increment year by 10 for each entry
		for (int i = 0; i < populationFigure / asterisk; i++) {
			cout << "*";
		}
		cout << endl;
	}
}