// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cstdlib> // For exit function
using namespace std;


void getLength_Width(double& length, double& width) {
	cout << "Enter the length: ";
	cin >> length;
	cout << "Enter the width: ";
	cin >> width;
	if (length <= 0 || width <= 0) {
		cout << "Length and width must be positive numbers." << endl;
		exit(1); // Exit the program if invalid input
	}
}
void calculateArea(double length, double width, double& area) {
	area = length * width;
}
void calcPerimeter(double length, double width, double& perimeter) {
	perimeter = 2 * (length + width);
}
void displayProperties(double length, double width, double area, double perimeter) {
	cout << fixed << setprecision(2);
	cout << "Area: " << area << endl;
	cout << "Perimeter: " << perimeter << endl;
	cout << "Do you want to process another rectangle? (type y for yes, any other key for no): ";
	char choice;
	cin >> choice;
	if (choice == 'y' || choice == 'Y') {
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

int main() {
	double length, width, area, perimeter;
	getLength_Width(length, width);
	calculateArea(length, width, area);
	calcPerimeter(length, width, perimeter);
	displayProperties(length, width, area, perimeter);
	return 0;
}