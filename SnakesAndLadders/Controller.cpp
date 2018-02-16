#include "Controller.h"

void Controller::setRoll(int i)
{
	roll = i;
}

int Controller::getRoll()
{
	return roll;
}

void Controller::movePlayer(Player &player)
{
	int newPosition;

	bool landedOnSnake = false;
	bool landedOnLadder = false;

	Dice dice;

	roll = dice.rollDie();

	newPosition = player.getPlayerPosition() + roll;

	// Snake Rolls
	for (int i = 0; i < NUM_OF_SNAKES; i++)
	{
		// If the player's new position equals any of the avaiable snake's heads, trigger this
		if (newPosition == snakeArray[i].getHead())
		{
			Console::setCursorPosition(Console::getCursorPosition().Y, 20);

			cout << player.getPlayerName() << " rolls a " << roll << ", lands on the head of a snake(" << snakeArray[i].getHead() << ") and moves to square " << snakeArray[i].getTail() << "." << endl;

			// Set player's position to be the snake's tail position
			newPosition = snakeArray[i].getTail();

			snakeArray[i].moveSnake(snakeArray);

			Console::setCursorPosition(22, 27);

			cout << player.getPlayerName() << " scared the snake! It moved to the tiles " << snakeArray[i].getHead() << " and " << snakeArray[i].getTail() << "!" << endl;

			landedOnSnake = true;
		}
	}

	// Ladder Rolls
	for (int i = 0; i < NUM_OF_LADDERS; i++)
	{
		// If the player's new position equals any of the avaiable ladder's bottom, trigger this
		if (newPosition == ladderArray[i].getBottom())
		{
			Console::setCursorPosition(Console::getCursorPosition().Y, 20);

			cout << player.getPlayerName() << " rolls a " << roll << ", lands on the bottom of a ladder(" << ladderArray[i].getBottom() << ") and moves to square " << ladderArray[i].getTop() << "." << endl;
			
			// Set player's position to be the snake's tail position
			newPosition = ladderArray[i].getTop();

			landedOnLadder = true;
		}
	}

	// Normal Roll

	// If player didn't land in either a snake or ladder, trigger this
	if (landedOnSnake == false && landedOnLadder == false)
	{
		// If player goes past 25
		if (newPosition > 25)
		{
			cout << player.getPlayerName() << " rolls a " << roll << " and stays in the same square." << endl;

			// Keep them in the same position
			newPosition -= roll;
		}
		else
		{
			cout << player.getPlayerName() << " rolls a " << roll << " and moves to square " << newPosition << "." << endl;
		}
	}

	// Assign new player's position
	player.setPlayerPosition(newPosition);
}