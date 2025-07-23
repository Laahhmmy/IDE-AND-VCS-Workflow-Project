// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;


void getLength_Width(double& length, double& width) {
	cout << "Enter the length: ";
	cin >> length;
	cout << "Enter the width: ";
	cin >> width;
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
}

int main() {
	double length, width, area, perimeter;
	getLength_Width(length, width);
	calculateArea(length, width, area);
	calcPerimeter(length, width, perimeter);
	displayProperties(length, width, area, perimeter);
	return 0;
}