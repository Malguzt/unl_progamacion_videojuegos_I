#include "Saw.h"

Saw::Saw()
{
	position = Vector2f(400, 500);
	texture.loadFromFile("img/saw.png");
	sprite.setTexture(texture);
	sprite.setPosition(position);
	sprite.setOrigin(32, 32);
}


Saw::~Saw()
{
}

void Saw::draw(RenderWindow &gm)
{
	sprite.rotate(-5);
	gm.draw(sprite);
}

Saw* Saw::getNext() {
	return next;
}

void Saw::setNext(Saw *newNext)
{
	next = newNext;
}

void Saw::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

void Saw::moveX(float x)
{
	position.x += x;
}
