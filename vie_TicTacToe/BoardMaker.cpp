#include "BoardMaker.h"

#include "Tile.h"

#include <vie/Window.h>

BoardMaker::BoardMaker() :
	tileWidth(32),
	tileHeight(32),
	offset(0),
	tiles(nullptr)
{
}

BoardMaker::~BoardMaker()
{
}

Tile** BoardMaker::getNewTilesArray()
{
	calculateBoardOffset();

	tiles = new Tile*[9];
	createTiles();

	return tiles;
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
	setTileGame(newTile);

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

	position += offset;

	return position;
}

void BoardMaker::calculateBoardOffset()
{
	float tileWidth = 96.0f;
	float boardWidth = 3 * tileWidth;
	float screenWidth = vie::Window::getScreenWidth();
	
	offset = (screenWidth - boardWidth) / 2.0f;
}

glm::vec2 BoardMaker::getPositionOnBoardByIndex(int index)
{
	glm::vec2 positionOnBoard;
	
	// Board size is 3x3
	positionOnBoard.x = index % 3;
	positionOnBoard.y = index / 3;

	return positionOnBoard;
}

void BoardMaker::setTileGame(Tile* tile)
{
	tile->setGame(game);
}

void BoardMaker::setGame(Game* ngame)
{
	game = ngame;
}

void BoardMaker::setTileSize(float tileW, float tileH)
{
	tileWidth = tileW;
	tileHeight = tileH;
}
