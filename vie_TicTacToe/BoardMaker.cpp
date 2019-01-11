#include "BoardMaker.h"

#include "Tile.h"

#include <vie/ObjectsManager.h>

BoardMaker::BoardMaker() :
	tileWidth(32),
	tileHeight(32),
	offsetX(0),
	offsetY(0),
	tiles(nullptr)
{
}

BoardMaker::~BoardMaker()
{
}

void BoardMaker::appendTilesIntoManager(vie::ObjectsManager* objectManager)
{
	for (int i=0; i<9; i++)
		objectManager->appendObject(tiles[i]);
}

void BoardMaker::makeBoard()
{
	tiles = new Tile*[9];
	createTiles();
}

void BoardMaker::createTiles()
{
	for (int i = 0; i < 9; i++)
		tiles[i] = getNewTileByIndex(i);
}

Tile* BoardMaker::getNewTileByIndex(int index)
{
	Tile* newTile = new Tile();
	setTileSize(newTile);
	setTilePositionByIndex(newTile, index);

	return newTile;
}

void BoardMaker::setTileSize(Tile* tile)
{
	glm::vec2 tileSize = glm::vec2(tileWidth, tileHeight);
	tile->setSize(tileSize);
}

void BoardMaker::setTilePositionByIndex(Tile* tile, int index)
{
	glm::vec2 tilePosition = getTilePositionByIndex(index);
	tile->setPosition(tilePosition);
}

glm::vec2 BoardMaker::getTilePositionByIndex(int index)
{
	glm::vec2 position = getPositionOnBoardByIndex(index);

	position.x *= tileWidth;
	position.y *= tileHeight;

	position.x += offsetX;
	position.y += offsetY;

	return position;
}

glm::vec2 BoardMaker::getPositionOnBoardByIndex(int index)
{
	glm::vec2 positionOnBoard;
	
	// Board size is 3x3
	positionOnBoard.x = index % 3;
	positionOnBoard.y = index / 3;

	return positionOnBoard;
}

void BoardMaker::setTileSize(float tileW, float tileH)
{
	tileWidth = tileW;
	tileHeight = tileH;
}

void BoardMaker::setOffset(float offX, float offY)
{
	offsetX = offX;
	offsetY = offY;
}