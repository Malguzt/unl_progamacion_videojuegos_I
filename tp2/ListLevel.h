#pragma once
#include "Level.h"
#include "List.h"
class ListLevel :
	public Level
{
public:
	ListLevel();
	~ListLevel();
	virtual void setY(float y);
	void releaseSaw();
	void draw(RenderWindow &gm);
protected:
	void clean();
	void add(Saw*);
private:
	List saws;
};

