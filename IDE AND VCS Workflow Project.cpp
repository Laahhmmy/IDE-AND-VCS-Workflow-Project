// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>


using namespace std;
int main() {
	double x, y, answer;

	x = 247; 
	y = 129;
	
	answer = x + y;

	cout << setw(10) << x << endl;
	cout << setw(7) << "+" << y << endl;
	cout << setw(10) << "----" << endl;
	cout << setw(10) << answer << endl;
		

}