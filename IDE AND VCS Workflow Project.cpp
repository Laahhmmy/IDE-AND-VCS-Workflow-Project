// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// This program reads a file named "Lineup.txt" containing student names,
// outputs each name, and determines the first and last names in alphabetical order.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	const string filename = "Lineup.txt";

	ifstream infile;
	infile.open(filename);
	if (infile.fail()) {
		cerr << "Could not find" << filename << endl;
		return(1); // Exit with error code
		
		// Read the file line by line
	}
	string studentName;
	while (getline(infile, studentName)) {
		cout << studentName << endl; // Output each student's name
		
	}
	string first, last;

	first = studentName;
	last = studentName;

	if (studentName < first) {
		first = studentName; // Update first if current name is smaller
	}
	if (studentName > last) {
		last = studentName; // Update last if current name is larger
	}
	infile.close(); // Close the file after reading

	cout << "First student: " << first << endl; // Output the first student
	cout << "Last student: " << last << endl; // Output the last student

	return (0);


}