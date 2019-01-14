#include "MainClass.h"

#include <vie/Graphics.h>
#include <vie/Window.h>
#include <vie/ObjectsManager.h>

#include "Tile.h"
#include "BoardMaker.h"
#include "Game.h"
#include "ResetButton.h"

MainClass::MainClass() :
	game(nullptr)
{
	runEngine("Tic Tac Toe", 400, 540);
}

MainClass::~MainClass()
{
}

void MainClass::onCreate()
{
	Tile::loadTextures();
	createGame();
	createRestartButton();
}

void MainClass::createGame()
{
	game = new Game();
	game->startGame(objectsManager);
}

void MainClass::createRestartButton()
{
	ResetButton* resetBtn = new ResetButton();
	resetBtn->init(game);
	objectsManager->appendObject(resetBtn);
	objectsManager->appendMouseInteractiveObject(resetBtn);
}

void MainClass::update(float et)
{
}

void MainClass::render(vie::Graphics* g)
{
	g->setBackgroundColor(vie::Color(30, 30, 30));
	game->render(g);
}
