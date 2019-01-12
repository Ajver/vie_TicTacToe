#include "MainClass.h"

#include <vie/Graphics.h>
#include <vie/Window.h>

#include "Tile.h"
#include "BoardMaker.h"

MainClass::MainClass()
{
	runEngine("Tic Tac Toe", 400, 600);
}

MainClass::~MainClass()
{
}

void MainClass::onCreate()
{
	Tile::loadTextures();

	float tileWidth = 96.0f;
	float boardWidth = 3 * tileWidth;
	float screenWidth = vie::Window::getScreenWidth();
	float offset = (screenWidth - boardWidth) / 2.0f;

	BoardMaker boardMaker;
	boardMaker.setTileSize(tileWidth, tileWidth);
	boardMaker.setOffset(offset, offset);
	boardMaker.makeBoard();
	boardMaker.appendTilesIntoManager(objectsManager);
}

void MainClass::update(float et)
{
}

void MainClass::render(vie::Graphics* g)
{
	g->setBackgroundColor(vie::Color(30, 30, 30));
}

MainClass::WhoseMove MainClass::getWhoseMove()
{
	return currentMove;
}

void MainClass::nextMove()
{

}

bool MainClass::isWin()
{
	return false;
}

bool MainClass::isGameEnd()
{
	return false;
}