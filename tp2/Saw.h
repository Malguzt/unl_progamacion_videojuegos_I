#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Saw
{
public:
	Saw();
	virtual ~Saw();
	void draw(RenderWindow &gm);
	Saw* getNext();
	void setNext(Saw *next);
	void setPosition(float x, float y);
	float moveX(float x);
	void setSpeed(int value);
	void move();
	bool inScreen(int width);
private:
	int speed;
	Sprite sprite;
	Texture texture;
	Saw *next = nullptr;
};