// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // For setw
using namespace std;

const int numQuestions = 20;
const string fileName = "CorrectAnswers.txt";
const string studentFileName = "StudentAnswers.txt";
void getAnswers(ifstream& inFile, char answers[]);
int gradeExam(const char correct[], const char studentAnswers[], char wrong[][2], int missed[]);
void writeReport(const char incorrect[][2], const int missed[], int numMissed);

int main() {
	ifstream inFile(fileName);
	if (inFile.fail()) {
		cerr << "Error opening file: " << fileName << endl;
		return 1;
	}
	ifstream studentFile(studentFileName);
	if (studentFile.fail()) {
		cerr << "Error opening file: " << studentFileName << endl;
		return 1;
	}
	char correctAnswers[numQuestions];
	char studentAnswers[numQuestions];
	char wrongAnswers[numQuestions][2]; // To store incorrect answers
	int missedQuestions[numQuestions]; // To store question numbers of missed answers

	getAnswers(inFile, correctAnswers);
	getAnswers(studentFile, studentAnswers);
	int numMissed = gradeExam(correctAnswers, studentAnswers, wrongAnswers, missedQuestions);
	writeReport(wrongAnswers, missedQuestions, numMissed);

}
void getAnswers(ifstream& inFile, char answers[]) {
	for (int i = 0; i < numQuestions; i++) {
		inFile >> answers[i];
	}

}
int gradeExam(const char correct[], const char studentAnswers[], char wrong[][2], int missed[]) {
	int numMissed = 0;
	for (int i = 0; i < numQuestions; i++) {
		if (studentAnswers[i] != correct[i]) {
			wrong[numMissed][1] = studentAnswers[i];
			missed[numMissed] = i; 
			wrong[numMissed][0] = correct[i];
			numMissed++;
		}
	}
	return numMissed;
}
void writeReport(const char incorrect[][2], const int missed[], int numMissed) {
	cout << "Questions Missed: " << numMissed << endl;
	double percent = (numQuestions - numMissed) / numQuestions * 100.0;	
	if (numMissed > 0) {
		cout << "Question  Correct  Student\n";
		for (int i = 0; i < numMissed; ++i) {
			cout << setw(4) << missed[i]
				<< setw(10) << incorrect[i][0]
				<< setw(9) << incorrect[i][1] << endl;
		}
	}
	cout << "Percentage Correct: " << fixed << setprecision(2) << percent << "%" << endl;
	if (numMissed == 0) {
		cout << "Congratulations! You got all questions correct!" << endl;
	} else if (percent >= 70.0) {
		cout << "You passed the exam!" << endl;
	}
	else {
		cout << "You failed the exam." << endl;
	}
}