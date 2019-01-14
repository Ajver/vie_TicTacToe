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
