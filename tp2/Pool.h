#pragma once
#include "Collection.h"
class Pool :
	public Collection
{
public:
	Pool();
	virtual ~Pool();
	void add(Saw *saw);
	virtual void setPosition(float x, float y);
};