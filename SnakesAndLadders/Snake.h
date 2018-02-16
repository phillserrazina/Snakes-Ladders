#ifndef SNAKE_H
#define SNAKE_H

#include<cstdlib>
#include<ctime>
#include "Player.h"

class Snake
{
private:
	int head;
	int tail;

public:
	Snake(int h, int t) : head(h), tail(t)
	{
		srand(static_cast<unsigned int>(time(NULL)));
		rand();
	}

	void setHead(int);
	int getHead();

	void setTail(int);
	int getTail();

	void moveSnake(Snake []);
};

#endif