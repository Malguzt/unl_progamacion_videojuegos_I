#pragma once
#include <SFML/Graphics.hpp>
#include "List.h"

using namespace sf;
using namespace std;
class Train
{
public:
	Train();
	~Train();
	void update();
	void draw(RenderWindow &gm);
	void setLevel(float);
	FloatRect getArea();
	void setPosition(Vector2f value);
	bool inScreen(int width);
protected:
private:
	void moveX(float x);
	Vector2f position;
	Sprite sprite;
	Texture texture;
	List wagons;
};

