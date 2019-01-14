#pragma once

#include <vie/Engine.h>

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

	void createGame();
	void createRestartButton();
};

