#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <game.h>
#include <string>
class TicTacToe : public Game
{
public:
	TicTacToe();
	~TicTacToe();
	virtual void play();
	virtual std::string get_title();
private:
	char sigil[3];
	int board[3][3];
	int winner();
	bool isGameOver();
	void drawBoard();
	bool isMoveLegal(int row, int column);
};
#endif

