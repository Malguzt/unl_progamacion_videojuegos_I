#include "ListLevel.h"
#include "List.h"

ListLevel::ListLevel()
{
}


ListLevel::~ListLevel()
{
}

void ListLevel::setY(float y)
{
	floorSprite.setPosition(0, y);
	saws.setPosition(floorSprite.getPosition().x, floorSprite.getPosition().y);
}

void ListLevel::releaseSaw()
{
	freeSaw = saws.getNext();
	freeSaw->setNext(nullptr);

	if (freeSaw != nullptr)
	{
		freeSaw->setSpeed(dificult * 3);
	}
}

void ListLevel::draw(RenderWindow & gm)
{
	saws.draw(gm);
	Level::draw(gm);
}

void ListLevel::clean()
{
	saws.clean();
}

void ListLevel::add(Saw *saw)
{
	saws.add(saw);
}
