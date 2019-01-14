#include "Board.h"

#include <vie/ObjectsManager.h>

#include "Game.h"
#include "BoardMaker.h"
#include "Tile.h"

Board::Board(Game* ngame)
{
	game = ngame;
}

Board::~Board()
{
}

void Board::createAndAppendIntoManager(vie::ObjectsManager* objectsManager)
{
	BoardMaker boardMaker;
	boardMaker.setGame(game);
	boardMaker.setTileSize(96.0f, 96.0f);
	tiles = boardMaker.getNewTilesArray();

	appendTilesIntoManager(objectsManager);
}

void Board::appendTilesIntoManager(vie::ObjectsManager* objectManager)
{
	for (int i = 0; i < 9; i++)
	{
		objectManager->appendObject(tiles[i]);
		objectManager->appendMouseInteractiveObject(tiles[i]);
	}
}

void Board::resetBoard()
{
	for (int i = 0; i < 9; i++)
		tiles[i]->reset();
}

bool Board::isWon()
{
	return isWonHorizontal() || isWonVertical() || isWonDiagonal();
}

bool Board::isWonHorizontal()
{
	for (int y = 0; y < 3; y++)
		if (isWonInRow(y))
			return true;
	
	return false;
}

bool Board::isWonInRow(int rowIndex)
{
	Tile* a = getTileFromPosition(0, rowIndex);
	Tile* b = getTileFromPosition(1, rowIndex);
	Tile* c = getTileFromPosition(2, rowIndex);
	return areWinning(a, b, c);
}

bool Board::isWonVertical()
{
	for (int x = 0; x < 3; x++)
		if (isWonInColumn(x))
			return true;

	return false;
}

bool Board::isWonInColumn(int colIndex)
{
	Tile* a = getTileFromPosition(colIndex, 0);
	Tile* b = getTileFromPosition(colIndex, 1);
	Tile* c = getTileFromPosition(colIndex, 2);
	return areWinning(a, b, c);
}

bool Board::isWonDiagonal()
{
	return isWonInFirstDiagonal() || isWonInSecondDiagonal();
}

bool Board::isWonInFirstDiagonal()
{
	// From Left-top to Right-bottom
	Tile* a = getTileFromPosition(0, 0);
	Tile* b = getTileFromPosition(1, 1);
	Tile* c = getTileFromPosition(2, 2);
	return areWinning(a, b, c);
}

bool Board::isWonInSecondDiagonal() 
{
	// From Right-top to Left-bottom
	Tile* a = getTileFromPosition(2, 0);
	Tile* b = getTileFromPosition(1, 1);
	Tile* c = getTileFromPosition(0, 2);
	return areWinning(a, b, c);
}

bool Board::areWinning(Tile* a, Tile* b, Tile* c)
{
	return haveTheSameState(a, b, c) && a->isNotEmpty();
}

bool Board::haveTheSameState(Tile* a, Tile* b, Tile* c)
{
	return a->getState() == b->getState() && b->getState() == c->getState();
}

Tile* Board::getTileFromPosition(int x, int y)
{
	int index = getTileIndexFromPosition(x, y);
	return tiles[index];
}

int Board::getTileIndexFromPosition(int x, int y)
{
	return (y * 3) + x;
}