#pragma once
#include "Collection.h"
class Level
{
public:
	Level();
	virtual ~Level();
	virtual void setY(float y) = 0;
	virtual void releaseSaw() = 0;
	virtual void draw(RenderWindow &gm);
	void setWidth(int width);
	float getY();
	void setDificult(int value);
	void moveSaw();
	bool checkCollision(FloatRect characterArea);
protected:
	virtual void clean() = 0;
	virtual void add(Saw*) = 0;
	Sprite floorSprite;
	int width;
	Saw *freeSaw = nullptr;
	int dificult;
private:
	Texture floorTexture;
};

