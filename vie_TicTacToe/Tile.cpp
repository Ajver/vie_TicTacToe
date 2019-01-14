#include "Tile.h"

#include <vie/IOManager.h>
#include <iostream>

#include "Game.h"

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

void Tile::setGame(Game* ngame)
{
	game = ngame;
}

void Tile::update(float et)
{
}

void Tile::render(vie::Graphics* g)
{
	if (shouldBeHovered())
		renderHovered(g);
	else
		renderDefault(g);

	renderCurrentState(g);
}

bool Tile::shouldBeHovered()
{
	return isMouseHover && canBeClicked();
}

void Tile::renderDefault(vie::Graphics* g)
{
	g->drawTexture(defaultTileTexture, position, size);
}

void Tile::renderHovered(vie::Graphics* g)
{
	g->drawTexture(hoverTileTexture, position, size);
}

void Tile::renderCurrentState(vie::Graphics* g)
{
	switch (currentState)
	{
	case TileState::SELECTED_X:
		renderX(g);
		break;
	case TileState::SELECTED_O:
		renderO(g);
		break;
	}
}

void Tile::renderX(vie::Graphics* g)
{
	g->drawTexture(X_Texture, position, size);
}

void Tile::renderO(vie::Graphics* g)
{
	g->drawTexture(O_Texture, position, size);
}

void Tile::onMousePress()
{
	if (canBeClicked())
	{
		setStateByCurrentMove();
		game->nextMove();
	}
}

bool Tile::canBeClicked()
{
	return currentState == TileState::EMPTY;
}

void Tile::setStateByCurrentMove()
{
	currentState = getTileStateFromWhoseMove();
}

Tile::TileState Tile::getTileStateFromWhoseMove()
{
	switch (game->getWhoseMove())
	{
	case Game::WhoseMove::X:
		return TileState::SELECTED_X;
		break;
	case Game::WhoseMove::O:
		return TileState::SELECTED_O;
		break;
	default:
		return TileState::EMPTY;
		break;
	}
}

void Tile::reset()
{
	currentState = TileState::EMPTY;
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