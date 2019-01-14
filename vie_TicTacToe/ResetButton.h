#pragma once

#include <vie/Object.h>

class Game;

class ResetButton : public vie::Object
{
public:
	ResetButton();
	~ResetButton();

	void init(Game* ngame);

	void render(vie::Graphics* g) override;

	void onMouseRelease() override;

private:
	Game* game;
	vie::Texture defaultTexture;
	vie::Texture hoverTexture;

	void loadTextures();
	void calculateSize();
	void calculatePosition();
	void calculateX();
	void calculateY();
};

