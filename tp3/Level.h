#pragma once
#include "List.h"
#include "Wagon.h"


class Level
{
public:
	Level();
	virtual ~Level();
	void setY(float y);
	void draw(RenderWindow &gm);
	void setWidth(int width);
	float getY();
	bool checkCollision(FloatRect trainArea);
	Wagon* takeTheWagon();
	int getWagonNumber();
protected:
private:
	Texture floorTexture;
	Sprite floorSprite;
	int width;
	int dificult;
	FloatRect stationArea;
	Wagon *wagon;
};

