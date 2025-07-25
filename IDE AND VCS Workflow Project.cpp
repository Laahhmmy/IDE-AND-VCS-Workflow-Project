// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// This program asks the user to input scores from five judges for a contestant.
#include <iostream>
using namespace std;

bool isLower(double, double); // Function to check if the first score is lower than the second
bool isHigher(double, double); // Function to check if the first score is higher than the second
double getScore(); // Function to get a valid score from the user
double calcAverage(double, double, double); // Function to calculate the average score after dropping the lowest and highest scores
int main() {
	double Score, total = 0, average, lowest, highest;
	cout << "Hello you will be giving the scores that these five judges will give to the contestant." << endl;
	cout << "Please enter the scores for the five judges. \nHowever, the lowest score and the highest score will be dropped when calculating the average." << endl;
	Score = getScore(); // Get the first score from the user
	lowest = Score;
	highest = Score;
	total = Score;

	for (int i = 1; i < 5; i++) { // Loop to get scores from the remaining four judges
		Score = getScore();
		total += Score;
		if (isLower(Score, lowest)) { // Check if the current score is lower than the lowest score recorded
			lowest = Score;
		}
		if (isHigher(Score, highest)) { // Check if the current score is higher than the highest score recorded
			highest = Score;
		}
	}
	cout << "After dropping the lowest score of " << lowest << " and the highest score of " << highest << endl;
	cout << "The average score is : " << calcAverage(total, lowest, highest) << endl;
	return 0;
}

double getScore() {
	double score;
	do {
		cout << "Enter a score between 0 and 10: ";
		cin >> score;
		if (score < 0 || score > 10) {
			cout << "Invalid score. Please try again." << endl;
		}
	} while (score < 0 || score > 10);
	return score;
}

bool isLower(double score1, double score2) {
	return score1 < score2;
}
bool isHigher(double score1, double score2) {
	return score1 > score2;
}
double calcAverage(double total, double lowest, double highest) {
	return (total - lowest - highest) / 3.0;
}