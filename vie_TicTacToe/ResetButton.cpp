#include "resetButton.h"

#include <vie/IOManager.h>
#include <vie/Window.h>

#include "Game.h"

ResetButton::ResetButton() :
	game(nullptr)
{
}

ResetButton::~ResetButton()
{
}

void ResetButton::init(Game* ngame)
{
	game = ngame;
	loadTextures();
	calculateSize();
	calculatePosition();
}

void ResetButton::loadTextures()
{
	defaultTexture = vie::IOManager::getTexture("Graphics/resetButton.png");
	hoverTexture = vie::IOManager::getTexture("Graphics/resetHoverButton.png");
}

void ResetButton::calculateSize()
{
	size.x = 128;
	size.y = 32;
}

void ResetButton::calculatePosition()
{
	calculateX();
	calculateY();
}

void ResetButton::calculateX()
{
	float screenWidth = vie::Window::getScreenWidth();
	position.x = screenWidth - size.x;
	position.x /= 2.0f;
}

void ResetButton::calculateY()
{
	float screenHeight = vie::Window::getScreenHeight();
	position.y = screenHeight - (size.y * 2.0f);
}

void ResetButton::render(vie::Graphics* g)
{
	if(isMouseHover)
		g->drawTexture(hoverTexture, position, size);
	else
		g->drawTexture(defaultTexture, position, size);
}

void ResetButton::onMouseRelease()
{
	game->resetGame();
}