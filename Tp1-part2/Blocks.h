#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

#define QUANTITY 10
class Blocks
{
public:
	Blocks();
	~Blocks();
	void draw(RenderWindow &gm);
	void checkHit(FloatRect);
private:
	int next = 0;
	Font font;
	Text text;
	Texture boxTexture;
	Sprite boxSprite;
	int numbers[QUANTITY];
	int sortedNumbers[QUANTITY];
	void createSortedNumbers();
};

