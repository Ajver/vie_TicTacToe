#pragma once

#include <vie/Object.h>

class Game;

class Tile : public vie::Object
{
public:
	enum class TileState
	{
		EMPTY,
		SELECTED_X,
		SELECTED_O
	};

public:
	Tile();
	~Tile();

	void setGame(Game* ngame);

	void update(float et) override;
	void render(vie::Graphics* g) override;

	TileState getState();
	bool isNotEmpty();

	void onMousePress() override;

	void reset();

	static void loadTextures();

private:
	Game* game;

	TileState currentState;

	bool shouldBeHovered();
	bool canBeClicked();
	void renderDefault(vie::Graphics* g);
	void renderHovered(vie::Graphics* g);
	void renderCurrentState(vie::Graphics* g);
	void renderX(vie::Graphics* g);
	void renderO(vie::Graphics* g);

	void setStateByCurrentMove();
	TileState getTileStateFromWhoseMove();

	static vie::Texture defaultTileTexture;
	static vie::Texture hoverTileTexture;
	static vie::Texture X_Texture;
	static vie::Texture O_Texture;

};

