#pragma once

class Board;

namespace vie
{ class ObjectsManager; }

class Game
{
public:
	Game();
	~Game();

	void startGame(vie::ObjectsManager* objectsManager);
	void restartGame();

	enum class WhoseMove
	{
		NOONE, X, O
	};

	WhoseMove getWhoseMove();

	void nextMove();

private:
	Board* board;
	WhoseMove currentMove;

	void switchMove();

};

