// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main() {
	cout << "Pattern A" << endl;
	const int n = 10;
	int patternA = 1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << "+";
			patternA++;
		}
		cout << endl;
	}
	cout << "Pattern B" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 10; j >= i; j--) {
			cout << "+";
			patternA--;
		}
		cout << endl;
	}
}