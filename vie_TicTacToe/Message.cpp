#include "Message.h"

#include <vie/IOManager.h>
#include <vie/Window.h>

Message::Message()
{
}

Message::~Message()
{
}

void Message::init(std::string texturePath)
{
	loadTextureFrom(texturePath);
	setSizeFromTexture();
	calculatePosition();
}

void Message::loadTextureFrom(std::string texturePath)
{
	messageTexture = vie::IOManager::getTexture(texturePath);
}

void Message::setSizeFromTexture()
{
	size.x = messageTexture.width;
	size.y = messageTexture.height;
}

void Message::calculatePosition()
{
	float screenWidth = vie::Window::getScreenWidth();
	position.x = screenWidth - size.x;
	position.x /= 2.0f;

	position.y = 370;
}

void Message::render(vie::Graphics* g)
{
	g->drawTexture(messageTexture, position, size);
}
