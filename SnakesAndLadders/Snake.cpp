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

void Snake::moveSnake(Snake availableSnakes[])
{
	int numOfSnakes = 2;
	int headMaxTiles = 24;
	int headMinTiles = 10;
	int tailTiles = 9;

	int newHead = rand() % (headMaxTiles - headMinTiles + 1) + headMinTiles;
	int newTail = rand() % tailTiles + 1;

	for (int i = 0; i < numOfSnakes; i++)
	{
		if (newTail == availableSnakes[i].getTail() || newHead == availableSnakes[i].getHead())
		{
			moveSnake(availableSnakes);
		}
	}

	setHead(newHead);
	setTail(newTail);
}