#include "Game.h"

#include <vie/IOManager.h>
#include <vie/Graphics.h>

#include "Board.h"

Game::Game() :
	board(nullptr),
	currentMove(WhoseMove::X),
	gameState(GameState::GAME),
	moveCounter(0)
{
}

Game::~Game()
{
}

void Game::startGame(vie::ObjectsManager* objectsManager)
{
	initMessages();
	createBoard(objectsManager);
}

void Game::createBoard(vie::ObjectsManager* objectsManager)
{
	board = new Board(this);
	board->createAndAppendIntoManager(objectsManager);
}

void Game::initMessages()
{
	x_wonMessage.init("Graphics/x_wonText.png");
	o_wonMessage.init("Graphics/o_wonText.png");
	drawMessage.init("Graphics/drawText.png");
}

void Game::resetGame()
{
	board->resetBoard();
	resetCurrentMove();
	gameState = GameState::GAME;
	moveCounter = 0;
}

void Game::resetCurrentMove()
{
	currentMove = WhoseMove::X;
}

void Game::render(vie::Graphics* g)
{
	switch (gameState)
	{
	case GameState::WON:
		renderWonMessage(g);
		break;
	case GameState::DRAW:
		renderDrawMessage(g);
		break;
	}
}

void Game::renderWonMessage(vie::Graphics* g)
{
	switch (currentMove)
	{
	case WhoseMove::X:
		renderX_wonMessage(g);
		break;
	case WhoseMove::O:
		renderO_wonMessage(g);
		break;
	}
}

void Game::renderX_wonMessage(vie::Graphics* g)
{
	x_wonMessage.render(g);
}

void Game::renderO_wonMessage(vie::Graphics* g)
{
	o_wonMessage.render(g);
}

void Game::renderDrawMessage(vie::Graphics* g)
{
	drawMessage.render(g);
}

Game::WhoseMove Game::getWhoseMove()
{
	return currentMove;
}

void Game::nextMove()
{
	moveCounter++;

	if (board->isWon())
		gameIsWon();
	else if (isDraw())
		gameIsDraw();
	else
		gameIsStillRunning();
}

void Game::gameIsWon()
{
	gameState = GameState::WON;
}

bool Game::isDraw()
{
	return moveCounter >= 9;
}

void Game::gameIsDraw()
{
	gameState = GameState::DRAW;
}

void Game::gameIsStillRunning()
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

bool Game::isGameStillRunning()
{
	return gameState == GameState::GAME;
}