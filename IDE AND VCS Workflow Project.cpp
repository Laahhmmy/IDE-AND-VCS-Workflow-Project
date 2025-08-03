// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int numQuestions = 20;
const string fileName = "CorrectAnswers.txt";
void getAnswers(string& inFile, char answers[]);
int gradeExam(const char correct[], const char studentAnswers[], char wrong[], int numberMissed[])

int main() {
	ifstream inFile(fileName);
	if (inFile.fail()) {
		cerr << "Error opening file: " << fileName << endl;
		return 1;
	}

}