#include "MainClass.h"

#include <vie/Graphics.h>
#include <vie/Window.h>

#include "Tile.h"
#include "BoardMaker.h"
#include "Game.h"

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

	Game* game = new Game();
	game->startGame(objectsManager);
}

void MainClass::update(float et)
{
}

void MainClass::render(vie::Graphics* g)
{
	g->setBackgroundColor(vie::Color(30, 30, 30));
}
