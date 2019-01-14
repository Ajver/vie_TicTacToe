#include "Tile.h"

#include <vie/IOManager.h>

#include <iostream>

vie::Texture Tile::defaultTileTexture;
vie::Texture Tile::hoverTileTexture;
vie::Texture Tile::X_Texture;
vie::Texture Tile::O_Texture;

Tile::Tile() :
	currentState(TileState::EMPTY)
{
}


Tile::~Tile()
{
}


void Tile::update(float et)
{
	
}

void Tile::render(vie::Graphics* g)
{
	g->drawTexture(defaultTileTexture, position, size);
}

void Tile::onMousePress()
{
	std::cout << "press!" << std::endl;
}

void Tile::onMouseMove()
{
	std::cout << "move in!" << std::endl;
}

Tile::TileState Tile::getState()
{
	return currentState;
}

void Tile::loadTextures()
{
	defaultTileTexture = vie::IOManager::getTexture("Graphics/defaultTile.png");
	hoverTileTexture = vie::IOManager::getTexture("Graphics/hoverTile.png");
	X_Texture = vie::IOManager::getTexture("Graphics/x.png");
	O_Texture = vie::IOManager::getTexture("Graphics/o.png");
}