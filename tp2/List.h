#pragma once
#include "Saw.h"
#include <SFML/Graphics.hpp>
class List
{
public:
	List();
	~List();
	void add(Saw *saw);
	void setPosition(float x, float y);
	void setPosition(Vector2f newPosition);
	void sortSaws();
	void draw(RenderWindow &gm);
	Saw* getNext();
	void clean();
private:
	Saw *first = nullptr;
	Vector2f position;
	Saw* getLast();
};