#ifndef GAME_H
#define GAME_H

#include<iostream>
#include<fstream>
#include<string>
#include "Dice.h"
#include "console.h"
#include "Board.h"
#include "Player.h"
#include "Controller.h"

class Game
{
public:
	Game() {}

	void setVisualSettings();
	void mainMenu();
	void playGame();
	void rulesMenu();
};

#endif

