#include "Blocks.h"
#include <sstream>


Blocks::Blocks()
{
	
	boxTexture.loadFromFile("img/package.png");
	boxSprite.setTexture(boxTexture);
	srand(time(NULL));
	for (int i = 0; i < QUANTITY; i++)
	{
		numbers[i] = rand() % 999 + 1;
	}
	createSortedNumbers();
	font.loadFromFile("sixty.ttf");
	text.setFont(font);
	text.setCharacterSize(30);
}


Blocks::~Blocks()
{
}

void Blocks::draw(RenderWindow & gm)
{
	Vector2f position;
	for (int i = 0; i < QUANTITY; ++i)
	{
		position = Vector2f(40 + i * 70, 300);
		boxSprite.setPosition(position);
		gm.draw(boxSprite);
		ostringstream ss;
		ss << numbers[i];
		text.setString(ss.str());
		text.setPosition(position + Vector2f(15, 20));
		if (numbers[i] < sortedNumbers[next]) {
			text.setColor(Color::Green);
		}
		else
		{
			text.setColor(Color::Black);
		}
		gm.draw(text);
	}
}

void Blocks::checkHit(FloatRect characterArea)
{
	FloatRect blockArea;
	for (int i = 0; i < QUANTITY; i++)
	{
		blockArea = FloatRect(Vector2f(40 + i * 70, 300), Vector2f(69, 70));
		if (characterArea.intersects(blockArea) && numbers[i] == sortedNumbers[next])
		{
			++next;
		}
	}
}

void Blocks::createSortedNumbers()
{
	int tmp;
	for (int i = 0; i < QUANTITY; ++i)
	{
		sortedNumbers[i] = numbers[i];
	}
	for (int i = 0; i < QUANTITY; ++i)
	{
		for (int j = 1; j < QUANTITY; ++j)
		{
			if (sortedNumbers[j - 1] > sortedNumbers[j])
			{
				tmp = sortedNumbers[j - 1];
				sortedNumbers[j - 1] = sortedNumbers[j];
				sortedNumbers[j] = tmp;
			}
		}
	}
}
