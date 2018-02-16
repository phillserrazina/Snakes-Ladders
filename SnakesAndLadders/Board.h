#ifndef BOARD_H
#define BOARD_H

#include<iostream>
#include<string>
#include "Player.h"
#include "console.h"

using namespace std;

class Player;

class Board
{
private:
	int numOfTiles;
	int boardWidth;
	int boardHeight;

public:
	Board();

	void setNumOfTiles(int);
	int getNumOfTiles();

	void setBoardWidth(int);
	int getBoardWidth();

	void setBoardHeight(int);
	int getBoardHeight();

	void drawBoard(int, int, Player, Player);
};

#endif

