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
	int getSpeed();
	void move();
	bool inScreen(int width);
	FloatRect getArea();
	Vector2f getPosition();
private:
	int speed = 0;
	Sprite sprite;
	Texture texture;
	Saw *next = nullptr;
};