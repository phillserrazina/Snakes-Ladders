#ifndef LADDER_H
#define LADDER_H

#include "Player.h"

class Ladder
{
private:
	int top;
	int bottom;

public:
	Ladder(int b, int t) : bottom(b), top(t) {}

	void setTop(int);
	int getTop();

	void setBottom(int);
	int getBottom();
};

#endif
