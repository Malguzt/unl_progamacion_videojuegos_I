#pragma once
#include "Level.h"
#include "Pool.h"
class PoolLevel :
	public Level
{
public:
	PoolLevel();
	~PoolLevel();
	virtual void setY(float y);
	void releaseSaw();
	void draw(RenderWindow &gm);
protected:
	void clean();
	void add(Saw*);
private:
	Pool leftSaws;
	Pool rightSaws;
	bool useLeft = true;
};

