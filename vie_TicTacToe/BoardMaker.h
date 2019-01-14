#pragma once

#include <glm/glm.hpp>

class Tile;

class BoardMaker
{
public:
	BoardMaker();
	~BoardMaker();

	Tile** getNewTilesArray();

	void setTileSize(float tileW, float tileH);

private:
	float tileWidth;
	float tileHeight;

	float offset;

	Tile** tiles;

	void createTiles();
	Tile* getNewTileByIndex(int index);
	void setTileSize(Tile* tile);
	void setTilePositionByIndex(Tile* tile, int index);
	void calculateBoardOffset();
	glm::vec2 getTilePositionByIndex(int index);
	glm::vec2 getPositionOnBoardByIndex(int index);
};

