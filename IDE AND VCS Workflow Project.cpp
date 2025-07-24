// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool isLower(double, double);
bool isHigher(double, double);
double getScore();
double calcAverage(double, double, double);
int main() {
	double Score, total = 0, average, lowest, highest;
	cout << "Hello you will be giving the scores that these five judges will give to the contestant." << endl;
	cout << "Please enter the scores for the five judges. \nHowever, the lowest score and the highest score will be dropped when calculating the average." << endl;
	Score = getScore();
	lowest = Score;
	highest = Score;
	total = Score;

	for (int i = 1; i < 5; i++) {
		Score = getScore();
		total += Score;
		if (isLower(Score, lowest)) {
			lowest = Score;
		}
		if (isHigher(Score, highest)) {
			highest = Score;
		}
	}
	cout << "After dropping the lowest " << lowest << " and the highest " << highest << endl;
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