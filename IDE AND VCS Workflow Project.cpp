// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

const string play = "play";
const string tie = "tie";
const string winner = "winner";
const string noWin = "nowinner";
const string Xwins = "X wins";
const string Owins = "O wins";

void initializeBoard(char board[3][3]);
void displayBoard(const char board[3][3]);
void placeToken(char board[3][3], char token);
void getLocation(int& row, int& col, const char board[3][3]);
string getBoardState(char board[3][3], char token);
string checkForWinner(char board[3][3], char token);



int main() {
    char board[3][3];
    char player1_token = 'X';
    char player2_token = 'O';
    string boardState = play;

    initializeBoard(board);
    displayBoard(board);

    while (boardState == play) {
        placeToken(board, player1_token);
        displayBoard(board);
        boardState = getBoardState(board, player1_token);
        if (boardState != play) break;

        placeToken(board, player2_token);
        displayBoard(board);
        boardState = getBoardState(board, player2_token);

    }
}
void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '*';
}
void displayBoard(const char board[3][3]) {
    cout << "\n  1 2 3\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";
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
        cout << "Enter row (1-3): ";
        cin >> row;
        cout << "Enter column (1-3): ";
        cin >> col;

        row--; // zero-based
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
