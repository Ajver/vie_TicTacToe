#pragma once

#include <vie/Engine.h>

class MainClass : public vie::Engine
{
public:
	MainClass();
	~MainClass();

	void update(float et) override;
	void render(vie::Graphics* g) override;
	void onCreate() override;

	enum class WhoseMove
	{ NOONE, X, O };

	WhoseMove getWhoseMove();
	
	void nextMove();

private:
	WhoseMove currentMove;
	
	bool isWin();
	bool isGameEnd();
};

