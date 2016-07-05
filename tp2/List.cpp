#include "List.h"
#define SAW_DIAMETER 64


List::List()
{
	first = NULL;
}


List::~List()
{
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

void List::setPosition(float x, float y)
{
	position = Vector2f(x, y);
	if (first != nullptr)
	{
		getLast()->setPosition(position.x + 35, position.y);
		sortSaws();
	}
}

void List::setPosition(Vector2f newPosition)
{
	setPosition(newPosition.x, newPosition.y);
}

void List::sortSaws()
{
	first->moveX(SAW_DIAMETER);
}

void List::draw(RenderWindow & gm)
{
	Saw *node = first;
	while (node != nullptr)
	{
		node->draw(gm);
		node = node->getNext();
	}
}

void List::clean()
{
	Saw *node = first;
	Saw *nextNode;
	while (node != nullptr)
	{
		nextNode = node->getNext();
		delete node;
		node = nextNode;
	}

	first = nullptr;
}

Saw* List::getNext()
{
	Saw *next = first;
	if (first != nullptr)
	{
		first = first->getNext();
	}

	return next;
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
