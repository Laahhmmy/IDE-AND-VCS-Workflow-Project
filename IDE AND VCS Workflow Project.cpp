// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void initializeBoard(char board[3][3]);
void displayBoard(const char board[3][3]);

int main() {
	char board[3][3]; // Declare the Tic Tac Toe board
	initializeBoard(board); // Initialize the board
	displayBoard(board); // Display the initialized board
	return 0;
}
void initializeBoard(char board[3][3]) {
	// Fill the board with spaces
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = '*';
		}
	}
}
void displayBoard(const char board[3][3]) {
	cout << "Tic Tac Toe Board:" << endl; // Print a header for the board
	cout << "-------------------" << endl; // Print a separator line
	cout << "   1 2 3" << endl;
	cout << "  -------\n"; // Print a separator line for the header
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << "| "; // Print row number followed by a vertical bar
		for (int j = 0; j < 3; j++) {
			cout << board[i][j] << " "; // Print each cell followed by a space
		}
		cout << endl; // New line after each row
	}
}
