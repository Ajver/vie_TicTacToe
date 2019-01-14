#include "Game.h"

#include "Board.h"

Game::Game() :
	board(nullptr),
	currentMove(WhoseMove::NOONE)
{
}

Game::~Game()
{
}

void Game::startGame(vie::ObjectsManager* objectsManager)
{
	board = new Board(this);
	board->createAndAppendIntoManager(objectsManager);
	resetCurrentMove();
}

void Game::resetGame()
{
	board->resetBoard();
	resetCurrentMove();
}

void Game::resetCurrentMove()
{
	currentMove = WhoseMove::X;
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
