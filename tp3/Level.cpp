#include "Level.h"

Level::Level()
{
	floorTexture.loadFromFile("img/floor.jpg");
	floorTexture.setRepeated(true);
	floorSprite.setTexture(floorTexture);
	wagon = new Wagon();
}

Level::~Level()
{
	delete wagon;
}

void Level::setWidth(int value)
{
	width = value;
	floorSprite.setTextureRect({ 0, 0, width, 10 });
}

float Level::getY()
{
	return floorSprite.getPosition().y;
}

void Level::draw(RenderWindow & gm)
{
	gm.draw(floorSprite);
	if (wagon != nullptr) {
		wagon->draw(gm);
	}
}

bool Level::checkCollision(FloatRect trainArea)
{
	return wagon != nullptr ? trainArea.intersects(wagon->getArea()) : false;
}

Wagon* Level::takeTheWagon()
{
	Wagon* aux = wagon;
	wagon = nullptr;
	return aux;
}

int Level::getWagonNumber()
{
	return wagon->getNumber();
}

void Level::setY(float y)
{
	floorSprite.setPosition(0, y);
	wagon->setPosition(rand() % (width - 240) + 120, getY() - 40);
}
