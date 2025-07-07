// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
// This program calculates the area of different geometric shapes based on user input.
int main() {
	
	cout << "Geometry Calculator\n";
	cout << "1. Calculate area of a Circle \n";
	cout << "2. Calculate area of a Rectangle \n";
	cout << "3. Calculate area of a Triangle \n";
	cout << "4. Exit \n";
	cout << "Please select an option (1-4): ";

	int choice;
	cin >> choice;
	switch (choice) {
		case 1: {
			// Area of Circle
			const double PI = 3.14159;
			double radius;
			
			cout << "Enter the radius of the circle: ";
			cin >> radius;
			double areaCircle = PI * radius * radius;
			if (radius < 0) {
				cout << "Radius must be positive" << endl;
				return 1; // Exit if invalid input
			}
			cout << "The area of the circle is: " << areaCircle << endl;
			break;
		}
		case 2: {
			// Area of Rectangle
			double length, width;
			cout << "Enter the length of the rectangle: ";
			cin >> length;
			cout << "Enter the width of the rectangle: ";
			cin >> width;
			double areaRectangle = length * width;
			if (length < 0 || width < 0) {
				cout << "Length and width must be positive" << endl;
				return 1; // Exit if invalid input
			}
			cout << "The area of the rectangle is: " << areaRectangle << endl;
			break;
		}
		case 3: {
			// Area of Triangle
			double base, height;
			
			cout << "Enter the base of the triangle: ";
			cin >> base;
			cout << "Enter the height of the triangle: ";
			cin >> height;
			double areaTriangle = 0.5 * base * height;
			if (base < 0 || height < 0) {
				cout << "Base and height must be positive" << endl;
				return 1; // Exit if invalid input
			}
			cout << "The area of the triangle is: " << areaTriangle << endl;
			break;
		}
		case 4:
			cout << "Exiting program." << endl;
			break;
		default:
			cout << "Invalid choice. Please select a valid option (1-4)." << endl;
}
	return 0;
}