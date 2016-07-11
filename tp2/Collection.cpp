#include "Collection.h"
#define SAW_DIAMETER 64

Collection::Collection()
{
	first = NULL;
}


Collection::~Collection()
{
	clean();
}

void Collection::setSense(int value)
{
}

void Collection::sortSaws()
{
	first->moveX(SAW_DIAMETER);
}

void Collection::draw(RenderWindow & gm)
{
	Saw *node = first;
	while (node != nullptr)
	{
		node->draw(gm);
		node = node->getNext();
	}
}

void Collection::clean()
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

Saw* Collection::getNext()
{
	Saw *next = first;
	if (first != nullptr)
	{
		first = first->getNext();
	}

	return next;
}

bool Collection::hasNest()
{
	return first != nullptr;
}
