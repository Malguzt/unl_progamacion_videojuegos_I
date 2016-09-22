#pragma once
#include "Wagon.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class List
{
public:
	List();
	virtual ~List();
	void add(Wagon *wagon);
	void setPosition(float x, float y);
	void sortWagons();
	void draw(RenderWindow &gm);
	Wagon* getNext();
	bool hasNest();
	void clean();
	void moveX(float x);
	bool inScreen(int width);
protected:
	Wagon * getLast();
	Wagon *first = nullptr;
	Vector2f position;
private:
};