#include "Level.h"

Level::Level()
{
	floorTexture.loadFromFile("img/floor.jpg");
	floorTexture.setRepeated(true);
	floorSprite.setTexture(floorTexture);
}

Level::~Level()
{
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
	if (freeSaw != nullptr)
	{
		freeSaw->draw(gm);
	}
	gm.draw(floorSprite);
}

void Level::setDificult(int value)
{
	dificult = value;
	clean();
	int max = dificult < 4 ? dificult : 4;
	for (int i = 0; i < max; i++) {
		add(new Saw());
	}
}

void Level::moveSaw()
{
	if (freeSaw != nullptr)
	{
		if (freeSaw->inScreen(width))
		{
			freeSaw->move();
		}
		else {
			freeSaw->inScreen(width);
			add(freeSaw);
			releaseSaw();
		}
	}
	else
	{
		if (dificult > 0)
		{
			releaseSaw();
		}
	}
}

bool Level::checkCollision(FloatRect characterArea)
{
	if (freeSaw != nullptr)
	{
		FloatRect sawArea = freeSaw->getArea();
		return characterArea.intersects(sawArea);
	}

	return 0;
}
