#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include<string>

using namespace std;

class Player
{
private:
	int playerPosition;
	string playerName;

public:
	Player();

	void setPlayerPosition(int);
	int getPlayerPosition();

	void setPlayerName(string);
	string getPlayerName();
};

#endif

