// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// This program calculates the area and perimeter of a rectangle based on user input for length and width.
#include <iostream>
#include <iomanip>
#include <cstdlib> // For exit function
using namespace std;


void getLength_Width(double& length, double& width) { // Function to get length and width from user
	cout << "Enter the length of the rectangle: ";
	cin >> length;
	cout << "Enter the width ofn the rectangle: ";
	cin >> width;
	if (length <= 0 || width <= 0) { // Closes the program if length or width is not positive
		cout << "Length and width must be positive numbers." << endl;
		exit(1); // Exit the program if invalid input
	}
}
void calculateArea(double length, double width, double& area) { // Function to calculate area of rectangle
	area = length * width;
}
void calcPerimeter(double length, double width, double& perimeter) { // Function to calculate perimeter of rectangle
	perimeter = 2 * (length + width);
}
void displayProperties(double length, double width, double area, double perimeter) { // Function to display the properties of the rectangle
	cout << fixed << setprecision(2);
	cout << "Area: " << area << endl;
	cout << "Perimeter: " << perimeter << endl;
	cout << "Do you want to process another rectangle? (type y for yes, any other key for no): ";
	char choice;
	cin >> choice;
	if (choice == 'y' || choice == 'Y') { // If user wants to process another rectangle
		double newLength, newWidth;
		getLength_Width(newLength, newWidth);
		double newArea, newPerimeter;
		calculateArea(newLength, newWidth, newArea);
		calcPerimeter(newLength, newWidth, newPerimeter);
		displayProperties(newLength, newWidth, newArea, newPerimeter);
	} else {
		cout << "Exiting the program." << endl;
	}
}

int main() { // Main function to execute the program
	double length, width, area, perimeter;
	getLength_Width(length, width); // Get length and width from user
	calculateArea(length, width, area); // Calculate area of rectangle
	calcPerimeter(length, width, perimeter); // Calculate perimeter of rectangle
	displayProperties(length, width, area, perimeter); // Display the properties of the rectangle
	return 0;
}