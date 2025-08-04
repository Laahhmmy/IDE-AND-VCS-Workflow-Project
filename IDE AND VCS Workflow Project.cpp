// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void initializeBoard(char board[3][3]);
void displayBoard(const char board[3][3]);
bool placeToken(char board[3][3], int row, int col, char token);

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
bool placeToken(char board[3][3], int row, int col, char token) {
	// Check if the position is valid and empty
	if (row >= 1 && row < 4 && col >= 1 && col < 4 && board[row][col] == '*') {
		board[row][col] = token; // Place the token
		return true; // Return true if placement was successful
	} 
	return false; // Return false if placement failed
}