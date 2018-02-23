#include "Snake.h"

void Snake::setHead(int i)
{
	head = i;
}

int Snake::getHead()
{
	return head;
}

void Snake::setTail(int i)
{
	tail = i;
}

int Snake::getTail()
{
	return tail;
}

// Generate a new position for the snake
void Snake::moveSnake(Snake availableSnakes[])
{
	// VARIABLES

	int numOfSnakes = 2;		// Num of existing snakes - 1
	int headMaxTiles = 24;		// Highest Tile where the head can be
	int headMinTiles = 10;		// Lowest Tile where the head can be
	int tailTiles = 9;			// Highest Tile where the tail can be

	int newHead = rand() % (headMaxTiles - headMinTiles + 1) + headMinTiles;	// New head position
	int newTail = rand() % tailTiles + 1;										// New tail position

	// Check to guarantee that the new position is not occupied
	for (int i = 0; i < numOfSnakes; i++)
	{
		// If the new tail OR new head is occupied, trigger this function again
		if (newTail == availableSnakes[i].getTail() || newHead == availableSnakes[i].getHead())
		{
			moveSnake(availableSnakes);
		}
	}

	// Set new head and tail
	setHead(newHead);
	setTail(newTail);
}