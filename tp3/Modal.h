#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
class Modal
{
public:
	Modal();
	~Modal();
	void draw(RenderWindow &gm, String message);
	void setRect(FloatRect rect);
private:
	RectangleShape modal;
	Font font;
	Text text;
};

