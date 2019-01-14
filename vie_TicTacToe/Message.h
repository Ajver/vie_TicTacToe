#pragma once

#include <vie/Object.h>

class Message : public vie::Object
{
public:
	Message();
	~Message();

	void init(std::string texturePath);

	void render(vie::Graphics* g) override;

private:
	vie::Texture messageTexture;

	void loadTextureFrom(std::string texturePath);
	void setSizeFromTexture();
	void calculatePosition();
};

