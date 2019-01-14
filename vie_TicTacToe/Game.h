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

private:
	Board* board;
};

