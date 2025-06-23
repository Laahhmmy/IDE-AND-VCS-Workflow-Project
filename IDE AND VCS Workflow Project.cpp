// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main() {
	double customers, percentoneormore, percentcitrus;
	double oneormore;
	customers = 16500; // Total number of customers surveyed
	percentoneormore = 15.0; // Percentage of customers purchasing one or more energy drinks per week
	percentcitrus = 58.0; // Percentage of those purchasing one or more energy drinks that prefer citrus flavored drinks
	oneormore = customers * percentoneormore / 100.0; 
	double citrus;
	citrus = oneormore * percentcitrus / 100.0;
	cout << "The approximate number of customers in the survey purchasing one or more energy drinks per week is " << oneormore << "." << endl;
	cout << "The approximate number of customers in the survey purchasing citrus flavored energy drinks per week is " << citrus << "." << endl;
	return 0;
}