#include "Game.h"

// Function that sets the Visual Settings (Console name and colour)
void Game::setVisualSettings()
{
	Console::setWindowTitle("Console Snakes & Ladders");	// Set Window Title
	Console::setTextBufferSize(30, 110);					// Set Console Size
	Console::setWindowPosition(200, 450);					// Set Console Position
	Console::setColour(Console::BLACK, Console::WHITE);		// Set bg colour to white and text colour to black.
	Console::clear();
}

// Function that handles the Main Menu
void Game::mainMenu()
{
	// VARIABLES

	string choice;

	// Menu
	Console::clear();

	Console::setCursorPosition(1, 40);
	Console::setColour(Console::RED, Console::WHITE);
	cout << "Welcome to Console Snakes & Ladders!" << endl << endl;

	Console::setColour(Console::BLACK, Console::WHITE);
	Console::setCursorPosition(3, 53);
	cout << "Commands: " << endl;
	Console::setCursorPosition(5, 55);
	cout << "play" << endl;
	Console::setCursorPosition(6, 55);
	cout << "rules" << endl;
	Console::setCursorPosition(7, 55);
	cout << "exit" << endl << endl;

	Console::setCursorPosition(9, 55);
	cin >> choice;

	// Move to according section

	if (choice == "play")
	{
		Console::clear();
		playGame();
	}
	else if (choice == "rules")
	{
		Console::clear();
		rulesMenu();
	}
	else if (choice == "exit")
	{
		Console::clear();
		Console::setCursorPosition(7, 48);
		Console::pause("Thank you for playing!");
	}
	else
	{
		Console::clear();
		Console::setCursorPosition(7, 48);
		cout << "That is not a valid command.";
		Sleep(2000);
		mainMenu();
	}
}

// Function that handles the Main Game
void Game::playGame()
{
	// VARIABLES

	Dice dice;
	Board board;
	Player playerOne;
	Player playerTwo;
	Controller controller;

	string nameOne;
	string nameTwo;

	bool playerOneGoesFirst = false;
	bool playerTwoGoesFirst = false;

	bool gameOver = false;

	fstream winFile("winLog.txt", ios::app);

	// GAME CORE

	board.drawBoard(40, 1, playerOne, playerTwo);

	// Get Player One Name
	Console::setCursorPosition(16, 40);
	cout << "Insert a name for Player 1: ";
	cin.ignore();
	getline(cin, nameOne);
	playerOne.setPlayerName(nameOne);

	Console::clear();
	board.drawBoard(40, 1, playerOne, playerTwo);

	// Get Player Two Name
	Console::setCursorPosition(16, 40);
	cout << "Insert a name for Player 2: ";
	getline(cin, nameTwo);
	playerTwo.setPlayerName(nameTwo);

	Console::clear();
	board.drawBoard(40, 1, playerOne, playerTwo);

	// Introduction Message: "Welcome *PlayerOne* and *PlayerTwo*!
	// A die is going to be rolled to determine who goes first."
	Console::setCursorPosition(16, 41);
	cout << "Welcome " << playerOne.getPlayerName() << " and " << playerTwo.getPlayerName() << "!" << endl;
	Sleep(1000);
	Console::setCursorPosition(17, 25);
	cout << "A die is going to be rolled to determine who goes first.";
	Sleep(2000);

	Console::clear();
	board.drawBoard(40, 1, playerOne, playerTwo);

	// Get rolls to see who goes first
	while (playerOneGoesFirst != true && playerTwoGoesFirst != true)
	{
		Console::setCursorPosition(16, 45);
		Sleep(1000);
		int playerOneRoll = dice.rollDie();
		int playerTwoRoll = dice.rollDie();

		// Print results
		cout << playerOne.getPlayerName() << " rolled a " << playerOneRoll << "!";
		Console::setCursorPosition(17, 45);
		cout << playerTwo.getPlayerName() << " rolled a " << playerTwoRoll << "!";
		Console::setCursorPosition(18, 45);

		// Print who goes first
		// P1 goes first
		if (playerOneRoll > playerTwoRoll)
		{
			cout << playerOne.getPlayerName() << " goes first!";
			playerOneGoesFirst = true;
		}
		// P2 goes first
		else if (playerOneRoll < playerTwoRoll)
		{
			cout << playerTwo.getPlayerName() << " goes first!";
			playerTwoGoesFirst = true;
		}
		// They draw
		else if (playerOneRoll == playerTwoRoll)
		{
			cout << "It's a draw!";
			Sleep(1500);
			Console::clear();
			board.drawBoard(40, 1, playerOne, playerTwo);
		}
	}

	Sleep(2500);
	Console::clear();
	board.drawBoard(40, 1, playerOne, playerTwo);

	// Game Loop
	while (gameOver != true)
	{
		// Draw new board
		Console::clear();
		board.drawBoard(40, 1, playerOne, playerTwo);

		// Player One goes first
		if (playerOneGoesFirst == true)
		{
			// Move Player One and display result
			Console::setCursorPosition(17, 35);
			controller.movePlayer(playerOne);
			Console::setCursorPosition(2, 2);
			Console::pause("Press any key to roll!");
			// Sleep(1000);

			// Player One Wins
			if (playerOne.getPlayerPosition() == 25)
			{
				gameOver = true;
				Console::clear();

				// Store Game Result into file
				winFile << playerOne.getPlayerName() << " won against " << playerTwo.getPlayerName() << endl;

				Console::setCursorPosition(10, 40);
				cout << playerOne.getPlayerName() << " won!";
				Sleep(3000);
				mainMenu();
			}

			if (gameOver != true)
			{
				// Move Player Two and display result
				Console::setCursorPosition(18, 35);
				controller.movePlayer(playerTwo);
				Console::setCursorPosition(2, 2);
				Console::pause("Press any key to roll!");
				// Sleep(1000);

				// Player Two Wins
			
				if (playerTwo.getPlayerPosition() == 25)
				{
					gameOver = true;
					Console::clear();

					// Store Game Result into file
					winFile << playerTwo.getPlayerName() << " won against " << playerOne.getPlayerName() << endl;

					Console::setCursorPosition(10, 40);
					cout << playerTwo.getPlayerName() << " won!";
					Sleep(3000);
					mainMenu();
				}
			}
		}

		// Player Two goes first
		else if (playerTwoGoesFirst == true)
		{
			// Move Player Two and display result
			Console::setCursorPosition(17, 35);
			controller.movePlayer(playerTwo);
			Console::setCursorPosition(2, 2);
			Console::pause("Press any key to roll!");
			// Sleep(1000);

			// Player Two wins
			if (playerTwo.getPlayerPosition() >= 25)
			{
				gameOver = true;
				Console::clear();

				// Store Game Result into file
				winFile << playerTwo.getPlayerName() << " won against " << playerOne.getPlayerName() << endl;

				Console::setCursorPosition(10, 40);
				cout << playerTwo.getPlayerName() << " won!";
				Sleep(3000);
				mainMenu();
			}

			if (gameOver != true)
			{
				// Move Player One and display result
				Console::setCursorPosition(18, 35);
				controller.movePlayer(playerOne);
				Console::setCursorPosition(2, 2);
				Console::pause("Press any key to roll!");
				// Sleep(1000);

				// Player One wins
				if (playerOne.getPlayerPosition() >= 25)
				{
					gameOver = true;
					Console::clear();

					// Store Game Result into file
					winFile << playerOne.getPlayerName() << " won against " << playerTwo.getPlayerName() << endl;

					Console::setCursorPosition(10, 40);
					cout << playerOne.getPlayerName() << " won!";
					Sleep(3000);
					mainMenu();
				}
			}
		}
	}
}

// Function that handles the Rules Menu.
void Game::rulesMenu()
{
	Console::clear();

	string choice;
	cout << "The rules of this game are very simple:" << endl << endl;
	cout << "1. A dice is rolled to determine who goes first (highest value goes first);" << endl;
	cout << "2. Both players roll the dice in turns until they reach tile 25;" << endl;
	cout << "3. If a player lands on the bottom of the ladder, they move to its' top;" << endl;
	cout << "4. If a player lands on the head of the snake, they move to its' tail;" << endl;
	cout << "5. To win a player must roll the exact number to land on square 25 or they do NOT move;" << endl;
	cout << endl << "Type 'back' to go to the main menu." << endl << endl;
	cin >> choice;

	while (choice != "back")
	{
		cout << "That is not a valid command. Type 'back' to go to the main menu." << endl;
		cin >> choice;
	}

	mainMenu();
}