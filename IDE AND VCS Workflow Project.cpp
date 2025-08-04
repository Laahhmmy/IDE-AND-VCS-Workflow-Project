// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// This program implements a simple Tic-Tac-Toe game for two players using a 3x3 board.
// Players take turns placing their tokens (X and O) on the board until one player wins or the game ends in a tie.
#include <iostream>
#include <string>
using namespace std;

const string play = "play"; // Game state constants
const string tie = "tie"; 
const string winner = "winner";
const string noWin = "nowinner";
const string Xwins = "X wins";
const string Owins = "O wins";

void initializeBoard(char board[3][3]); // Initializes the game board with empty cells
void displayBoard(const char board[3][3]); // Displays the current state of the game board
void placeToken(char board[3][3], char token); // Places a player's token on the board at the specified location
void getLocation(int& row, int& col, const char board[3][3]); // Gets the row and column from the player for placing their token
string getBoardState(char board[3][3], char token); //  Determines the current state of the board
string checkForWinner(char board[3][3], char token); // Checks if the specified player has won the game



int main() {
	char board[3][3]; // 3x3 game board
	char player1_token = 'X'; // Player 1's token
	char player2_token = 'O'; // Player 2's token
	string boardState = play; // Current state of the game

	initializeBoard(board); // Initialize the game board
	displayBoard(board);// Display the initial state of the board

    while (boardState == play) { // Loop until the game is over
		cout << "Player 1's turn (X):\n"; // Print Player 1's turn to place their token
        placeToken(board, player1_token);
        displayBoard(board);
        boardState = getBoardState(board, player1_token);
        if (boardState != play) break;
        if (boardState == play) {
        cout << "Player 2's turn (O):\n";
        placeToken(board, player2_token);
        displayBoard(board);
        boardState = getBoardState(board, player2_token);
    }
    }
	if (boardState == Xwins) { // Check if Player 1 has won
        cout << "Player 1 (X) wins! Congratulations!\n";
    }
	else if (boardState == Owins) { // Check if Player 2 has won
        cout << "Player 2 (O) wins! Congratulations!\n";
    }
	else if (boardState == tie) { // Check if the game ended in a tie
        cout << "It's a tie! Well played both!\n";
    }
    return 0;

}

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '*';
}
void displayBoard(const char board[3][3]) {
    cout << "\n    1 2 3\n";
	cout << "   -------\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";
		cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void placeToken(char board[3][3], char token) {
    int row, col;
    getLocation(row, col, board);
    board[row][col] = token;
}

void getLocation(int& row, int& col, const char board[3][3]) {
    while (true) {
        cout << "Enter row number it must be (1-3): ";
        cin >> row;
        cout << "Enter column row number it must be (1-3): ";
        cin >> col;

        row--; 
        col--;

        if (row < 0 || row > 2 || col < 0 || col > 2)
            cout << "Invalid input. Try again.\n";
        else if (board[row][col] != '*')
            cout << "Cell already taken. Choose another.\n";
        else
            break;
    }
}

string getBoardState(char board[3][3], char token) {
    if (checkForWinner(board, token) == winner) {
        return (token == 'X') ? Xwins : Owins;
    }
    // Check if any space left
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == '*')
                return play;  // still spaces, keep playing

    return tie;  // no spaces left and no winner → tie
}

string checkForWinner(char board[3][3], char token) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == token && board[i][1] == token && board[i][2] == token)
            return winner;
        if (board[0][i] == token && board[1][i] == token && board[2][i] == token)
            return winner;
    }
    // Check diagonals
    if ((board[0][0] == token && board[1][1] == token && board[2][2] == token) ||
        (board[0][2] == token && board[1][1] == token && board[2][0] == token))
        return winner;

    return noWin;
}
