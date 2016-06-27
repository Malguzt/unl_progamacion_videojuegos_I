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
	saw->setPosition(position.x, position.y);
	if (first == nullptr) 
	{
		first = saw;
	}
	else
	{
		Saw *node = first;
		while (node->getNext() != nullptr)
		{
			node->moveX(SAW_DIAMETER);
			node = node->getNext();
		}
		node->setNext(saw);
	}
}

void List::setPosition(float x, float y)
{
	position = Vector2f(x, y);
	Saw *node = first;
	int partial = SAW_DIAMETER / 2;
	while (node != nullptr)
	{
		node->setPosition(position.x + partial, position.y);
		partial += SAW_DIAMETER;
		node = node->getNext();
	}
}

void List::setPosition(Vector2f newPosition)
{
	setPosition(newPosition.x, newPosition.y);
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

Saw * List::getLast()
{
	Saw *node = first;
	while (node->getNext() != nullptr)
	{
		node = node->getNext();
	}

	return node;
}
