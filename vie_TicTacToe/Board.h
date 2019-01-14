#pragma once

class Game;
class Tile;

namespace vie
{ class ObjectsManager; }

class Board
{
public:
	Board(Game* ngame);
	~Board();

	void createAndAppendIntoManager(vie::ObjectsManager* objectsManager);
	void resetBoard();

private:
	Game* game;

	Tile** tiles;

	void appendTilesIntoManager(vie::ObjectsManager* objectsManager);
};

