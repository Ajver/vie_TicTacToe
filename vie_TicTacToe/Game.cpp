#include "Game.h"

#include "Board.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::startGame(vie::ObjectsManager* objectsManager)
{
	board = new Board(this);
	board->createAndAppendIntoManager(objectsManager);
}

void Game::restartGame()
{
}

