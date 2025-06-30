// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
	double principal, rate;
	double timesCompounded;
	cout << "What is the balance in your savings account? ";
	cin >> principal;
	cout << "What is the annual interest rate (in percent)? ";
	cin >> rate;
	cout << "How many times is the interest compounded per year? ";
	cin >> timesCompounded;

	rate = rate / 100; // Convert percentage to decimal
	double balance = principal * pow(1 + (rate / timesCompounded), timesCompounded);
	double interest = balance - principal;

	cout << fixed << setprecision(2); // Set output to 2 decimal places
	cout << "Interest Rate: " << rate * 100 << "%" << endl;
	cout << "Times Compounded: " << timesCompounded << endl;
	cout << "Principal: $" << principal << endl;
	cout << "Interest: $" << interest << endl;
	cout << "Amount in savings: $" << balance << endl;

	return 0;
}