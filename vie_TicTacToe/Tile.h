#pragma once

#include <vie/Object.h>

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

	void update(float et) override;
	void render(vie::Graphics* g) override;

	TileState getState();

	void onMousePress() override;
	void onMouseMove() override;

	static void loadTextures();

private:
	TileState currentState;
	
	static vie::Texture defaultTileTexture;
	static vie::Texture hoverTileTexture;
	static vie::Texture X_Texture;
	static vie::Texture O_Texture;

};

