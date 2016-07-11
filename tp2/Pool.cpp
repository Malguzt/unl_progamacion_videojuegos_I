#include "Pool.h"



Pool::Pool()
{
}


Pool::~Pool()
{
}

void Pool::add(Saw * saw)
{
	if (first == nullptr)
	{
		saw->setPosition(position.x + sense * 35, position.y);
	}
	else {
		saw->setPosition(first->getPosition().x + sense * 64, first->getPosition().y);
	}

	saw->setNext(first);
	first = saw;

}

void Pool::setPosition(float x, float y)
{
	position = Vector2f(x, y);
}

void Pool::setSense(int value)
{
	if (value == 1 || value == -1) {
		sense = value;
	}
}
