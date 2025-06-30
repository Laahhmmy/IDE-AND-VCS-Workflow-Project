// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cmath>

//In this program, we will request the user to input the balance in their savings account, the annual interest rate, and the number of times the interest is compounded per year.
//After thatm we will calculate and display the interest earned and the total amount in the savings account.
using namespace std;
int main() {
	double principal, rate;
	double timesCompounded;
	cout << "What is the balance in your savings account? ";
	cin >> principal;
	cout << "What is the annual interest rate (type without percent - Example: 4.25)? ";
	cin >> rate;
	cout << "How many times is the interest compounded per year? ";
	cin >> timesCompounded;

	rate = rate / 100; // Convert percentage to decimal
	double balance = principal * pow(1 + (rate / timesCompounded), timesCompounded);
	double interest = balance - principal;

	cout << fixed << setprecision(2); // Set output to 2 decimal places
	cout << "Interest Rate: " << setw(13) << rate * 100 << "%" << endl;
	cout << "Times Compounded: " << setw(10) << timesCompounded << endl;
	cout << "Principal: " << setw(10) << "$" << principal << endl;
	cout << "Interest: " << setw(13) << "$" << interest << endl;
	cout << "Amount in savings: " << setw(2) << "$" << balance << endl;

	return 0;
}