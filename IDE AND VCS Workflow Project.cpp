// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// This program collects information about student's exam answers, grades the exam, and generates a report of missed questions and percentage correct.

#include <iostream>
#include <fstream> // For file operations
#include <string> // For string operations
#include <iomanip> // For setw
using namespace std;

const int numQuestions = 20; // Set constant for Number of questions in the exam
const string fileName = "CorrectAnswers.txt"; // File containing correct answers
const string studentFileName = "StudentAnswers.txt"; // File containing student's answers
void getAnswers(ifstream& inFile, char answers[]); // Function to read answers from a file
int gradeExam(const char correct[], const char studentAnswers[], char wrong[][2], int missed[]); // Function to grade the exam and find incorrect answers
void writeReport(const char incorrect[][2], const int missed[], int numMissed); // Function to write the report of missed questions and percentage correct

int main() { // Main function to execute the program
	ifstream inFile(fileName); // Open the file containing correct answers
	if (inFile.fail()) {
		cerr << "Error opening file: " << fileName << endl;
		return 1;
	}
	ifstream studentFile(studentFileName); // Open the file containing student's answers
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
	return 0;
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
	cout << "Exam Report Details" << endl;
	cout << "Questions Missed: " << numMissed << endl;
	double percent = 100.0 * (numQuestions - numMissed) / numQuestions;
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