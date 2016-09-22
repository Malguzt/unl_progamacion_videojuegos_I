#include "Wagon.h"
#include <string>

using namespace std;

Wagon::Wagon()
{
	String file = "img/wagon_n.png";
	file[10] = rand() % 4 + '1';
	texture.loadFromFile(file);

	texture.setSmooth(true);
	sprite.setTexture(texture);
}


Wagon::~Wagon()
{
}

void Wagon::draw(RenderWindow &gm)
{
	gm.draw(sprite);
}

Wagon* Wagon::getNext() {
	return next;
}

void Wagon::setNext(Wagon*newNext)
{
	next = newNext;
}

void Wagon::setPosition(float x, float y)
{
	sprite.setPosition(x - texture.getSize().x, y);
	if (next != nullptr) {
		next->setPosition(sprite.getPosition().x, y);
	}
}

float Wagon::moveX(float x)
{
	if (getNext() != nullptr)
	{
		sprite.setPosition(getNext()->moveX(x) + x, sprite.getPosition().y);
	}
	return sprite.getPosition().x;
}

bool Wagon::inScreen(int width)
{
	float x = sprite.getPosition().x;
	bool inScreen = x > 0 && x < width + texture.getSize().x;
	if (next != nullptr) {
		inScreen = inScreen || next->inScreen(width);
	}
	return inScreen;
}

FloatRect Wagon::getArea()
{
	return FloatRect(sprite.getPosition().x - 32, sprite.getPosition().y - 32, 60, 60);
}

Vector2f Wagon::getPosition()
{
	return sprite.getPosition();
}