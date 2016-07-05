#include "Saw.h"

Saw::Saw()
{
	texture.loadFromFile("img/saw.png");
	texture.setSmooth(true);
	sprite.setColor(Color(rand(), rand(), rand()));
	sprite.setTexture(texture);
	sprite.setOrigin(32, 32);
}


Saw::~Saw()
{
}

void Saw::draw(RenderWindow &gm)
{
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

float Saw::moveX(float x)
{
	if (getNext() != nullptr)
	{
		sprite.setPosition(getNext()->moveX(x) + x, sprite.getPosition().y);

	}
	return sprite.getPosition().x;
}

void Saw::setSpeed(int value)
{
	speed = value;
}

void Saw::move()
{
	sprite.rotate(speed);
	sprite.setPosition(sprite.getPosition().x + speed, sprite.getPosition().y);
}

bool Saw::inScreen(int width)
{
	float x = sprite.getPosition().x;
	return x > 0 && x < width + 64;
}