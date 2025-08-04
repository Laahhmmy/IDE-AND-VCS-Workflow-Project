// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// This program reads team names from a file and allows the user to input a team name in order to
// find the number of World Series wins for that team. It also reads the winners from another file
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

const string teamsFile = "teams.txt";
const string winnersFile = "WorldSeriesWinners.txt";
void getTeams(ifstream& teamsFile, vector<string>& teams);
int findWinners(const string& teamName, vector<string>& winners);

int main() {
	vector<string> teams;
	vector<string> winners;
	ifstream inFile(teamsFile);
	if (inFile.fail()) {
		cerr << "Error opening file: " << teamsFile << endl;
		return 1;
	}
	ifstream winnersInFile(winnersFile);
	if (winnersInFile.fail()) {
		cerr << "Error opening file: " << winnersFile << endl;
		return 1;
	}
	getTeams(inFile, teams);
	getTeams(winnersInFile, winners);
	cout << "Team Names:" << endl;
	for (const auto& team : teams) {
		cout << team << endl;
	}
	string teamName;
	cout << "Enter the name of a team (enter quit to end): " << endl;
	getline(cin, teamName);
	while (teamName != "quit") {
		int count = findWinners(teamName, winners);
		cout << "The team " << teamName << " has won the World Series " << count << " times." << endl;
		cout << "Enter the name of a team (enter quit to end): " << endl;
		getline(cin, teamName);
	}
	return 0;
}
void getTeams(ifstream& teamsFile, vector<string>& teams) {
	string team;
	while (getline(teamsFile, team)) {
		teams.push_back(team);
	}
}
int findWinners(ifstream& winnersFile, vector<string>& winners) {
	string winner;
	int count = 0;
	while (getline(winnersFile, winner)) {
		winners.push_back(winner);
		count++;
	}
	return count;
}