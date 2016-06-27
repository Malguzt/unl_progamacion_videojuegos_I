#include "Level.h"

Level::Level()
{
	floorTexture.loadFromFile("img/floor.jpg");
	floorTexture.setRepeated(true);
	floorSprite.setTexture(floorTexture);
	freeSaw = nullptr;
}

Level::~Level()
{
}

void Level::setY(float y)
{
	floorSprite.setPosition(0, y);
	saws.setPosition(floorSprite.getPosition());
}

void Level::setWidth(int width)
{
	floorSprite.setTextureRect({ 0, 0, width, 10 });
}

float Level::getY()
{
	return floorSprite.getPosition().y;
}

void Level::draw(RenderWindow & gm)
{
	saws.draw(gm);
	if (freeSaw != nullptr)
	{
		freeSaw->draw(gm);
	}
	gm.draw(floorSprite);
}

void Level::setDificult(int value)
{
	dificult = value;
	saws.clean();
	for (int i = 0; i < dificult; i++) {
		saws.add(new Saw());
	}
}
