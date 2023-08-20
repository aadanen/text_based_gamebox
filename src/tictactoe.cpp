#include <iostream>
#include <iomanip>
#include <string>
#include <tictactoe.h>

TicTacToe::TicTacToe()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = 0;
		}
	}
	sigil[0] = '.';
	sigil[1] = 'X';
	sigil[2] = 'O';
}


TicTacToe::~TicTacToe() {}


std::string TicTacToe::get_title()
{
    return "Tic Tac Toe";
}


int TicTacToe::winner()
{
	int winning_player = 0;
	// Loops through the rows to see if any of them are the same in every column
	// If so, returns the value of that row
	// otherwise returns 0
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0)
		{
			winning_player = board[i][0];
		}
	}


	// Same as checkRows but loops through columns
	for (int j = 0; j < 3; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != 0)
		{
			winning_player = board[0][j];
		}
	}


	// Top left to bottom right diagonal
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != 0)
	{
		winning_player = board[0][0];
	}
	// Bottom left to top right diagonal
	else if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][2] != 0)
	{
		winning_player = board[2][0];
	}

	return winning_player;	
}


bool TicTacToe::isGameOver()
{
	if (winner() == 2 || winner() == 1) { return true; }
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i][j] == 0)
				return false;
	return true; // There are no empty squares, therefore it is a tie.
}

                        

bool TicTacToe::isMoveLegal(int row, int column)
{
	if (row > 2 || row < 0 || column > 2 || column < 0) { return false; }
	else if (board[row][column] != 0) { return false; }
        return true;
}


// draw the board using "." for empty squares
// or 'X' or 'O' for player 1 or player 2
void TicTacToe::drawBoard()
{
        std::cout << "  0 1 2" << std::endl;
        for (int i = 0; i < 3; i++)
        {
                std::cout << i;
                for (int j = 0; j < 3; j++)
                {
                        std::cout << std::setw(2) << sigil[board[i][j]];
                }
                std::cout << std::endl;
        }
}


void TicTacToe::play()
{
        int player = 1;
        int row, column, result;
        bool legalMove;
        
        // starting board
        drawBoard();
        while(!isGameOver()){
                std::cout << "Player " << player << "(" << sigil[player] << "), your move?";
                std::cin >> row >> column;
                legalMove = isMoveLegal(row, column);
                while(!legalMove){
                        std::cout << "Player " << player << "(" << sigil[player] << "), your move?";
                        std::cin >> row >> column;
                        legalMove = isMoveLegal(row, column);
                }
                board[row][column] = player;
                drawBoard();
                player = 3 - player;
        }
        // game over
        result = winner();
        if (result == 0){
                std::cout << "Tie Game" << std::endl;
        } else {
                std::cout << "Player " << result << "(" << sigil[result] << ") wins!" << std::endl;
        }
}

