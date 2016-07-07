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
	void releaseSaw();
	void moveSaw();
	bool checkCollision(FloatRect characterArea);
private:
	int dificult;
	int width;
	List saws;
	Saw *freeSaw = nullptr;
	Texture floorTexture;
	Sprite floorSprite;
};

