// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// This program reads population figures from a file and displays them as a bar chart using asterisks.
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
		return 1; 
	}
	cout << "My Town Population Growth" << endl;
	cout << "Each asterisk (*) represents " << asterisk << " people." << endl;
	while (infile >> populationFigure) {
		if (populationFigure < 0) {
			cout << "Invalid population figure: " << populationFigure << " for year " << year << endl;
			continue; 
		}
		cout << year << ": ";
		year += 20; 
		for (int i = 0; i < populationFigure / asterisk; i++) {
			cout << "*";
		}
		cout << endl;
	}
}