#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include<string>

using namespace std;

class Player
{
private:
	int roll;
	int noOfMoves;

	int playerPosition;
	string playerName;

public:
	Player();

	void setPlayerRoll(int);
	int getPlayerRoll();

	void setNoOfMoves(int);
	int getNoOfMoves();

	void setPlayerPosition(int);
	int getPlayerPosition();

	void setPlayerName(string);
	string getPlayerName();
};

#endif

