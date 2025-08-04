// IDE AND VCS Workflow Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

void initializeBoard(char board[3][3]);
void displayBoard(const char board[3][3]);
void placeToken(char board[3][3], char token);
void getLocation(int& row, int& col, const char board[3][3]);
string getBoardState(char board[3][3], char token);
string checkForWinner(char board[3][3], char token);


int main() {
   
}
