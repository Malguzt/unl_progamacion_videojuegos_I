#include "Level.h"

Level::Level()
{
	floorTexture.loadFromFile("img/floor.jpg");
	floorTexture.setRepeated(true);
	floorSprite.setTexture(floorTexture);
	stationTexture.loadFromFile("img/station.png");
	stationSprite.setTexture(stationTexture);
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
	wagon->draw(gm);
}

bool Level::checkCollision(FloatRect trainArea)
{
	return trainArea.intersects(FloatRect(stationSprite.getPosition(), (Vector2f) stationTexture.getSize()));
}

void Level::setY(float y)
{
	floorSprite.setPosition(0, y);
	wagon->setPosition(rand() % width, getY() - 40);
}
