#ifndef DICE_H
#define DICE_H

#include<iostream>
#include<cstdlib>
#include<ctime>

class Dice
{
private:
	int numOfSides;

public:
	Dice();

	void setSides(int);
	int getSides();

	int rollDie();
};

#endif

