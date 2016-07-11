#pragma once
#include "Saw.h"
class Collection
{
public:
	Collection();
	virtual ~Collection();
	virtual void add(Saw *saw) = 0;
	virtual void setPosition(float x, float y) = 0;
	virtual void setSense(int value);
	void sortSaws();
	void draw(RenderWindow &gm);
	Saw* getNext();
	bool hasNest();
	void clean();
protected:
	Saw *first = nullptr;
	Vector2f position;
private:
};

