// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// This program reads team names from a file and allows the user to input a team name in order to
// find the number of World Series wins for that team. It also reads the winners from another file
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

const string teamsFile = "teams.txt"; // File containing team names
const string winnersFile = "WorldSeriesWinners.txt"; // File containing World Series winners
void getTeams(ifstream& teamsFile, vector<string>& teams); // Function to read team names from a file
int FindWinners(const string& teamName, vector<string>& winners); // Function to find the number of wins for a given team

int main() { // Main function to execute the program
	vector<string> teams; // Vector to store team names
	vector<string> winners; // Vector to store World Series winners
	ifstream inFile(teamsFile); // Open the teams file
	if (inFile.fail()) { // Check if the teams file can be opened
		cerr << "Error opening file: " << teamsFile << endl;
		return 1;
	}
	ifstream winnersInFile(winnersFile); // Open the winners file
	if (winnersInFile.fail()) { // Check if the winners file can be opened
		cerr << "Error opening file: " << winnersFile << endl;
		return 1;
	}
	getTeams(inFile, teams); // Read team names from the file
	getTeams(winnersInFile, winners); // Read World Series winners from the file
	cout << "Team Names:" << endl; 
	for (const auto& team : teams) { // Display the team names
		cout << team << endl;
	}
	string teamName;
	cout << "\nEnter the name of a team (enter quit to end): " << endl;
	getline(cin, teamName);
	while (teamName != "quit") {
		int count = FindWinners(teamName, winners);
		cout << "\nThe team " << teamName << " has won the World Series " << count << " times." << endl;
		cout << "Enter the name of a team (enter quit to end): " << endl;
		getline(cin, teamName);
	}
	return 0;
}
void getTeams(ifstream& teamsFile, vector<string>& teams) { 
	string team;
	while (getline(teamsFile, team)) { // Read each line from the file
		teams.push_back(team); // Add the team name to the vector
	}
}
int FindWinners(const string& teamName, vector<string>& winners) {
	int count = 0;
	for (const string& winner : winners) { // Iterate through the winners vector
		if (winner == teamName) {
			count++;
		}
}
	return count;
}