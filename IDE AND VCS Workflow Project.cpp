// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
	const int asterisk = 1000;
	int year, populationFigure;
	string fileName;
	ifstream infile;
	cout << "Enter the name of the file to read: ";
	cin >> fileName;
	infile.open(fileName);
	if (!infile) {
		cout << "Error opening file: " << fileName << endl;
		return 1; // Exit with error code
	}

}