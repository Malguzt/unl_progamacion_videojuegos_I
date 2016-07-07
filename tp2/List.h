#pragma once
#include "Saw.h"
#include <SFML/Graphics.hpp>
#include "Collection.h"
class List : public Collection
{
public:
	List();
	~List();
	void add(Saw *saw);
	virtual void setPosition(float x, float y);
private:
	Saw* getLast();
};