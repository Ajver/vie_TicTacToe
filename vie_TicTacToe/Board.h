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

	bool isWon();

private:
	Game* game;

	Tile** tiles;

	void appendTilesIntoManager(vie::ObjectsManager* objectsManager);

	bool isWonVertical();
	bool isWonHorizontal();
	bool isWonDiagonal();
	bool isWonInRow(int rowIndex);
	bool isWonInColumn(int colIndex);
	bool isWonInFirstDiagonal();
	bool isWonInSecondDiagonal();

	bool areWinning(Tile* a, Tile* b, Tile* c);
	bool haveTheSameState(Tile* a, Tile* b, Tile* c);
	Tile* getTileFromPosition(int x, int y);
	int getTileIndexFromPosition(int x, int y);
};

