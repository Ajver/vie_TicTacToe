#include "MainClass.h"

#include <vie/Graphics.h>
#include <vie/Window.h>
#include <vie/ObjectsManager.h>
#include <vie/InputManager.h>
#include <vie/IOManager.h>

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
	loadTextures();
	createGame();
	createRestartButton();
}

void MainClass::loadTextures()
{
	x_texture = vie::IOManager::getTexture("Graphics/x.png");
	o_texture = vie::IOManager::getTexture("Graphics/o.png");
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

	if(game->isGameStillRunning())
		renderCursor(g);
}

void MainClass::renderCursor(vie::Graphics* g)
{
	static glm::vec2 size(32, 32);
	glm::vec2 pos = vie::InputManager::getMousePosition() - (size);

	switch (game->getWhoseMove())
	{
	case Game::WhoseMove::X:
		g->drawTexture(x_texture, pos, size);
		break;
	case Game::WhoseMove::O:
		g->drawTexture(o_texture, pos, size);
		break;
	}
}
