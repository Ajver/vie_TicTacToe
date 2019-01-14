#pragma once

#include "Message.h"

class Board;

namespace vie
{
	class ObjectsManager;
	class Graphics;
}

class Game
{
public:
	Game();
	~Game();

	void startGame(vie::ObjectsManager* objectsManager);
	void resetGame();

	void render(vie::Graphics* g);

	enum class WhoseMove
	{
		NOONE, X, O
	};

	enum class GameState
	{
		GAME, WON, DRAW
	};

	WhoseMove getWhoseMove();

	void nextMove();
	bool isGameStillRunning();

private:
	Board* board;
	int moveCounter;
	WhoseMove currentMove;
	GameState gameState;

	Message x_wonMessage;
	Message o_wonMessage;
	Message drawMessage;
	
	void initMessages();
	void createBoard(vie::ObjectsManager* objectsManager);

	void renderWonMessage(vie::Graphics* g);
	void renderX_wonMessage(vie::Graphics* g);
	void renderO_wonMessage(vie::Graphics* g);
	void renderDrawMessage(vie::Graphics* g);

	void switchMove();
	void resetCurrentMove();

	bool isDraw();

	void gameIsWon();
	void gameIsDraw();
	void gameIsStillRunning();
};

