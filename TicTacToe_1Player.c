//Tic Tac Toe vs computer


#include<stdio.h>
#include<stdlib.h>


char player = 'X';
char AI = 'O';
char board[3][3];

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
	printf("\n");
	for (int i = 0; i < 3; i++)
	{
		printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
		if (i < 2) printf("|---|---|---|\n");
	}
	printf("\n");
}

int IsWinner(char symbol)
{
	for (int i = 0; i < 3; i++)
	{
		if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
			|| (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol))
		{
			return 1;
		}
		if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
			|| (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol))
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
			if (board[i][j] == (' ')) return 0;
		}
	}
	return 1;
}

void PlayerMove()
{
	int rows, cols;
	while(1)
	{
		printf("Enter your move\n");
		printf("Enter row and column from value 0 - 2 ");
		scanf_s("%d %d", &rows, &cols);
		if (rows >= 0 && rows < 3 && cols >= 0 && cols < 3 && board[rows][cols] == ' ')
		{
			board[rows][cols] = player;
			break;
		}
		else
		{
			printf("Invalid move, try again \n");
		}

	}
}

/*
void AIMove()
{
	//AI will block or try to win
	for (char symbol = AI; symbol == AI || symbol == player; symbol = player)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == ' ')
				{
					board[i][j] = symbol;
					if (IsWinner(symbol))
					{
						if (symbol == AI) return;//AI Wins
						board[i][j] = AI;
						return;
					}
					board[i][j] = ' ';
				}

			}
		}
	}
	//Pick first available spot
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
			{
				board[i][j] = AI;
				return;
			}
		}
	}
}

*/
	void AIMove()
{
    // Step 1: Try to win
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = AI;
                if (IsWinner(AI))
                {
                    return; // AI wins
                }
                board[i][j] = ' ';
            }
        }
    }

    // Step 2: Try to block player
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = player;
                if (IsWinner(player))
                {
                    board[i][j] = AI; // block player
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

    // Step 3: Pick first available spot
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = AI;
                return;
            }
        }
    }
}


void PlayGame()
{
	InitializeBoard();
	PrintBoard();
	while (1)
	{
		PlayerMove();
		PrintBoard();

		if (IsWinner(player))
		{
			printf("Player wins\n");
			break;
		}
		if (IsDraw())
		{
			printf("Game ends in draw\n");
			break;
		}

		AIMove();
		PrintBoard();
		if (IsWinner(AI))
		{
			printf("AI wins\n");
			break;
		}
		if (IsDraw())
		{
			printf("Game ends in draw\n");
			break;
		}

	}

}

int main()
{
	printf("Welcome to Tic Tac Toe vs the computer");

	PlayGame();



	printf("\n\n");
	return 0;
}
