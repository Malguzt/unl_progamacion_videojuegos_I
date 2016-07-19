#include "Blocks.h"



Blocks::Blocks()
{
	boxTexture.loadFromFile("img/package.png");
	boxSprite.setTexture(boxTexture);
}


Blocks::~Blocks()
{
}

void Blocks::draw(RenderWindow & gm)
{
	for (int i = 0; i < QUANTITY; ++i)
	{
		boxSprite.setPosition(40 + i * 70, 300);
		gm.draw(boxSprite);
	}
}
