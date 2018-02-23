#include "Player.h"

using namespace std;

Player::Player()
{
	playerName = "Default";
	playerPosition = 1;
	noOfMoves = 0;
}

void Player::setPlayerRoll(int i)
{
	roll = i;
}

int Player::getPlayerRoll()
{
	return roll;
}

void Player::setNoOfMoves(int i)
{
	noOfMoves = i;
}

int Player::getNoOfMoves()
{
	return noOfMoves;
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