// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// This program reads a file named "Lineup.txt" containing student names,
// outputs each name, counts how many names there are, and determines the first and last names in alphabetical order.

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
	int numberOfStudents = 0; // Variable to count the number of students
	while (getline(infile, studentName)) {
		numberOfStudents++; // Increment the count for each student name read
	}

	string first, last; // Variables to hold the first and last names in alphabetical order

	
	cout << "Number of students: " << numberOfStudents << endl; // Output the number of students
	cout << "First student: " << first << endl; // Output the first student in alphabetical order
	cout << "Last student: " << last << endl; // Output the last student in alphabetical order

	return (0);


}