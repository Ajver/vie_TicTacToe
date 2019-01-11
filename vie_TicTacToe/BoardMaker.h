#pragma once

#include <glm/glm.hpp>

namespace vie
{
	class ObjectsManager;
}

class Tile;

class BoardMaker
{
public:
	BoardMaker();
	~BoardMaker();

	void makeBoard();
	void appendTilesIntoManager(vie::ObjectsManager* objectManager);

	void setTileSize(float tileW, float tileH);
	void setOffset(float offX, float offY);

private:
	float tileWidth;
	float tileHeight;

	float offsetX;
	float offsetY;

	Tile** tiles;

	void createTiles();
	Tile* getNewTileByIndex(int index);
	void setTileSize(Tile* tile);
	void setTilePositionByIndex(Tile* tile, int index);
	glm::vec2 getTilePositionByIndex(int index);
	glm::vec2 getPositionOnBoardByIndex(int index);
};

