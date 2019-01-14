#pragma once

#include <vie/Engine.h>
#include <vie/Texture.h>

class Game;

class MainClass : public vie::Engine
{
public:
	MainClass();
	~MainClass();

	void update(float et) override;
	void render(vie::Graphics* g) override;
	void onCreate() override;

private:	
	Game* game;
	vie::Texture x_texture;
	vie::Texture o_texture;

	void loadTextures();
	void createGame();
	void createRestartButton();

	void renderCursor(vie::Graphics* g);
};

