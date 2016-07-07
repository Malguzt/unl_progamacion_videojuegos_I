#include "List.h"


List::List()
{
}


List::~List()
{
	clean();
}

void List::add(Saw *saw)
{
	saw->setPosition(position.x + 35, position.y);
	if (first == nullptr)
	{
		first = saw;
	}
	else
	{
		getLast()->setNext(saw);
		sortSaws();
	}
}

Saw * List::getLast()
{
	Saw *node = first;
	while (node != nullptr && node->getNext() != nullptr)
	{
		node = node->getNext();
	}

	return node;
}


void List::setPosition(float x, float y)
{
	position = Vector2f(x, y);
	if (first != nullptr)
	{
		getLast()->setPosition(position.x + 35, position.y);
		sortSaws();
	}
}