#include "List.h"

List::List()
{
	first = NULL;
	srand(time(NULL));
}


List::~List()
{
	clean();
}

void List::sortWagons()
{
	first->moveX(20);
}

void List::draw(RenderWindow & gm)
{
	Wagon *node = first;
	while (node != nullptr)
	{
		node->draw(gm);
		node = node->getNext();
	}
}

void List::clean()
{
	Wagon *node = first;
	Wagon *nextNode;
	while (node != nullptr)
	{
		nextNode = node->getNext();
		delete node;
		node = nextNode;
	}

	first = nullptr;
}

void List::moveX(float x)
{
	first->moveX(x);
	sortWagons();
}

bool List::inScreen(int width)
{
	return first->inScreen(width);
}

Wagon* List::getNext()
{
	Wagon *next = first;
	if (first != nullptr)
	{
		first = first->getNext();
	}

	return next;
}

bool List::hasNest()
{
	return first != nullptr;
}

void List::add(Wagon *wagon)
{
	wagon->setPosition(position.x + 70, position.y);
	wagon->added();
	if (first == nullptr)
	{
		first = wagon;
	}
	else
	{
		getLast()->setNext(wagon);
		first->moveX(70);
	}
}

void List::release()
{
	Wagon *last = first;
	Wagon *previous = nullptr;

	while (last != nullptr && last->getNext() != nullptr)
	{
		previous = last;
		last = last->getNext();
	}
	if (previous != nullptr) {
		previous->setNext(nullptr);
	}
	if (last != nullptr) {
		delete last;
	}
	if (last == first) {
		first = nullptr;
	}
}

void List::setPosition(float x, float y)
{
	position = Vector2f(x, y);
	if (first != nullptr)
	{
		first->setPosition(x, y);
	}
}

Wagon * List::getLast()
{
	Wagon *node = first;
	while (node != nullptr && node->getNext() != nullptr)
	{
		node = node->getNext();
	}

	return node;
}