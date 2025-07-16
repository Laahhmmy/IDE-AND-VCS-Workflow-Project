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
	string name;
	string firstName = name;
	string lastName = name;
	int numberOfStudents = 1; // Initialize the number of students
	ifstream infile;
	infile.open(filename);
	if (infile.fail()) {
		cerr << "Could not find" << filename << endl;
		return(1); // Exit with error code
		
		// Read the file line by line
	}
	if (infile >> name) {
		firstName = name; 
		lastName = name; 
		cout << name << endl; 
		while (infile >> name) {
			numberOfStudents++; 
			cout << name << endl; 
			if (name < firstName) {
				firstName = name; 
			}
			if (name > lastName) {
				lastName = name; 
			}
		}
	}
	
	cout << "Number of students: " << numberOfStudents << endl; 
	cout << "First student: " << firstName << endl; 
	cout << "Last student: " << lastName << endl; 

	return (0);


}