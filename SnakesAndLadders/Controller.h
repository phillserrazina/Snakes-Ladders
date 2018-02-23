#ifndef CONTROLLER_H
#define CONTROLLER_H

#include<iostream>
#include "console.h"
#include "Player.h"
#include "Snake.h"
#include "Dice.h"
#include "Ladder.h"

using namespace std;

class Controller
{
private:
	static const int NUM_OF_SNAKES = 3;
	Snake snakeArray[NUM_OF_SNAKES] = { { 13, 2 },{ 19, 6 },{ 24, 3 } };

	static const int NUM_OF_LADDERS = 3;
	Ladder ladderArray[NUM_OF_LADDERS] = { { 4, 17 },{ 7, 18 },{ 15, 22 } };

public:
	Controller() {}

	void movePlayer(Player &);
};

#endif