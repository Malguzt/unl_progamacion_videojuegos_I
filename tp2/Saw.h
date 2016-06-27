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
	void moveX(float x);
private:
	Vector2f position;
	Sprite sprite;
	Texture texture;
	Saw *next = nullptr;
};