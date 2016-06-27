#pragma once
#include "List.h"
class Level
{
public:
	Level();
	~Level();
	void setY(float y);
	void setWidth(int width);
	float getY();
	void draw(RenderWindow &gm);
	void setDificult(int value);
private:
	int dificult;
	List saws;
	Saw *freeSaw;
	Texture floorTexture;
	Sprite floorSprite;
};

