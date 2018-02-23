#include "Dice.h"

using namespace std;

Dice::Dice()
{
	srand(static_cast<unsigned int>(time(NULL)));
	rand();

	numOfSides = 6;
}

void Dice::setSides(int i)
{
	numOfSides = i;
}

int Dice::getSides()
{
	return numOfSides;
}

// Function rollDie() returns a random number between 0 and numberOfSides.
int Dice::rollDie()
{
	int result = rand() % numOfSides + 1;

	return result;
}