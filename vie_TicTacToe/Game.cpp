#include "Game.h"

#include "Board.h"

Game::Game() :
	board(nullptr),
	currentMove(WhoseMove::O)
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

Game::WhoseMove Game::getWhoseMove()
{
	return currentMove;
}

void Game::nextMove()
{
	switchMove();
}

void Game::switchMove()
{
	switch (currentMove)
	{
	case WhoseMove::X:
		currentMove = WhoseMove::O;
		break;
	case WhoseMove::O:
		currentMove = WhoseMove::X;
		break;
	}
}
