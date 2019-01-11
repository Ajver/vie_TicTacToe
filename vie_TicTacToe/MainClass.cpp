#include "MainClass.h"

#include <vie/Graphics.h>

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

	BoardMaker boardMaker;
	boardMaker.setTileSize(96, 96);
	boardMaker.setOffset(20, 10);
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