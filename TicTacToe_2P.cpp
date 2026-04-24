//TicTacToe in cpp

#include<iostream>
#include<stdio.h>

using namespace std;
char board[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
string p1, p2;
char player1 = 'X';
char player2 = 'O';


void InitializeBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = (' ');
		}
	}
}

void PrintBoard()
{
	cout << "   |   |   \n";
	cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " \n";
	cout << "___|___|___\n";
	cout << "   |   |   \n";
	cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " \n";
	cout << "___|___|___\n";
	cout << "   |   |   \n";
	cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " \n";
	cout << "   |   |   \n";
}

int IsWinner()
{
	for (int i = 0; i < 3; i++)
	{
		//Check for rows and cols if its straight line 'X'
		if ((board[i][0] == player1 && board[i][1] == player1 && board[i][2] == player1)
			|| (board[0][i] == player1 && board[1][i] == player1 && board[2][i] == player1))
		{
			return 1;
		}
		//Check for diagonals 'X'
		if ((board[0][0] == player1 && board[1][1] == player1 && board[2][2] == player1)
			|| (board[0][2] == player1 && board[1][1] == player1 && board[2][0] == player1))
		{
			return 1;
		}

	}
	return 0;
}

int IsDraw()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == (' '))
			{
				return 0;
			}
		}
	}
	return 1;
}

void switchplayer()
{
	
	if ((player1 == 'X'))
	{
		player2 = 'O';
	}
	else
	{
		player1 = 'X';
	}
	
}

void MakeMove(char currentPlayer) 
{
	int choice;
	cout << "Player " << currentPlayer << ", enter a position (1-9): ";
	cin >> choice;

	// Convert choice (1-9) into row/col
	int row = (choice - 1) / 3;
	int col = (choice - 1) % 3;

	// Check if spot is empty
	if (board[row][col] == ' ') 
	{
		board[row][col] = currentPlayer;
	}
	else 
	{
		cout << "That spot is already taken! Try again.\n";
		MakeMove(currentPlayer); // retry
	}
}





int main()
{
	int board[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
	string p1, p2;

		InitializeBoard();
		char currentPlayer = 'X';

		cout << "Enter name of player 1: ";
		cin >> p1;
		cout << "Enter name of player 2: ";
		cin >> p2;

		while (true) {
			PrintBoard();
			MakeMove(currentPlayer);

			if (IsWinner()) {
				PrintBoard();
				cout << "Player " << currentPlayer << " wins!\n";
				break;
			}

			if (IsDraw()) {
				PrintBoard();
				cout << "It's a draw!\n";
				break;
			}

			// Switch player
			if (currentPlayer == 'X') 
			{
				currentPlayer = 'O';
			}
			else {
				currentPlayer = 'X';
			}
		}

		return 0;
	}


	
	
	
	
	









