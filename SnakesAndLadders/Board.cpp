#include "Board.h"

Board::Board()
{
	numOfTiles = 25;
	boardWidth = 28;
	boardHeight = 11;
}

void Board::setNumOfTiles(int i)
{
	numOfTiles = i;
}

int Board::getNumOfTiles()
{
	return numOfTiles;
}

void Board::setBoardWidth(int i)
{
	boardWidth = i;
}

int Board::getBoardWidth()
{
	return boardWidth;
}

void Board::setBoardHeight(int i)
{
	boardHeight = i;
}

int Board::getBoardHeight()
{
	return boardHeight;
}

void Board::drawBoard(int boardX, int boardY, Player playerOne, Player playerTwo)
{
	int offSet = 2.5;
	int offSetMultiplier = 5;

	// ### BOARD EDGES ###
	Console::setCursorPosition(boardY, boardX);
	Console::drawLineH(boardWidth, '-');

	Console::setCursorPosition(boardY + offSet * 6, boardX);
	Console::drawLineH(boardWidth, '-');

	Console::setCursorPosition(boardY + 1, boardX - 1);
	Console::drawLineV(boardHeight, '|');

	Console::setCursorPosition(boardY + 1, boardX + boardWidth);
	Console::drawLineV(boardHeight, '|');

	// ### BOARD TILES ###

	Console::setCursorPosition(boardY + offSet*offSetMultiplier, boardX);
	
	for (int i = 1; i <= 25; i++)
	{
		// Change square colour depending on what player is stepping it
		if (i == playerOne.getPlayerPosition() && i == playerTwo.getPlayerPosition())
		{
			Console::setColour(Console::BLACK, Console::LIGHT_BLUE);
		}
		else if (i == playerOne.getPlayerPosition())
		{
			Console::setColour(Console::BLACK, Console::LIGHT_RED);
		}
		else if (i == playerTwo.getPlayerPosition())
		{
			Console::setColour(Console::BLACK, Console::LIGHT_GREEN);
		}

		// Change row when its edge is drawn
		if (i == 21 || i == 16 || i == 11 || i == 6)
		{
			offSetMultiplier--;
			Console::setCursorPosition(boardY + offSet * offSetMultiplier, boardX);
		}

		// Add a space for perfectionism due to 1digit--2digit relation
		if (i == 1 || i == 6)
			cout << " ";

		if (i < 9)
		{
			cout << i;

			Console::setColour(Console::BLACK, Console::WHITE);

			if (i != 5)
			{
				cout << "     ";
			}
		}
		else
		{
			cout << i;

			Console::setColour(Console::BLACK, Console::WHITE);

			if (i != 10 && i != 15 && i != 20 && i != 25)
			{
				cout << "    ";
			}
		}
	}
}