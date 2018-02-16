#include "Player.h"

using namespace std;

Player::Player()
{
	playerName = "Default";
	playerPosition = 1;
}

void Player::setPlayerPosition(int i)
{
	playerPosition = i;
}

int Player::getPlayerPosition()
{
	return playerPosition;
}

void Player::setPlayerName(string s)
{
	playerName = s;
}

string Player::getPlayerName()
{
	return playerName;
}