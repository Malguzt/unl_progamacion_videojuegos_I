#include "PoolLevel.h"
#include "Pool.h"


PoolLevel::PoolLevel()
{
}


PoolLevel::~PoolLevel()
{
}

void PoolLevel::setY(float y)
{
	floorSprite.setPosition(0, y);
	rightSaws.setPosition(floorSprite.getTextureRect().width, floorSprite.getPosition().y);
	leftSaws.setPosition(floorSprite.getPosition().x, floorSprite.getPosition().y);
	rightSaws.setSense(-1);
	leftSaws.setSense(1);
}

void PoolLevel::releaseSaw()
{
	int sense;
	if (useLeft)
	{
		freeSaw = leftSaws.getNext();
		useLeft = leftSaws.hasNest();
		sense = 1;
	}
	else
	{
		freeSaw = rightSaws.getNext();
		useLeft = !rightSaws.hasNest();
		sense = -1;
	}

	freeSaw->setNext(nullptr);

	if (freeSaw != nullptr)
	{
		freeSaw->setSpeed(dificult * 3 * sense);
	}
}

void PoolLevel::draw(RenderWindow & gm)
{
	leftSaws.draw(gm);
	rightSaws.draw(gm);
	Level::draw(gm);
}

void PoolLevel::clean()
{
	rightSaws.clean();
	rightSaws.clean();
}

void PoolLevel::add(Saw *saw)
{
	if (saw->getSpeed() > 0)
	{
		rightSaws.add(saw);
	}
	else
	{
		leftSaws.add(saw);
	}
}
