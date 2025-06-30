// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

// This program deplays a simple math problem and waits for the user to press ENTER before revealing the answer.
using namespace std;
int main() {
	double x, y, answer;

	x = 247; 
	y = 129;
	
	answer = x + y;

	cout << "Hello, this is a math problem that I have given you." << endl;
	cout << "Please solve the following problem:" << endl;
	cout << "Press ENTER in order to reveal the answer after you have solved it." << endl;
	cout << setw(10) << x << endl;
	cout << setw(7) << "+" << y << endl;
	cout << setw(10) << "----";
	cin.get(); // Wait for user input before displaying the answer
	cout << setw(10) << answer << endl;
		

}