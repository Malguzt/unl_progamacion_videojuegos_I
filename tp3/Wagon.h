#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Wagon
{
public:
	Wagon();
	~Wagon();
	void draw(RenderWindow &gm);
	Wagon* getNext();
	void setNext(Wagon *next);
	void setPosition(float x, float y);
	float moveX(float x);
	bool inScreen(int width);
	FloatRect getArea();
	Vector2f getPosition();
	void added();
	int getNumber();
private:
	bool inTheTrain = false;
	Font font;
	Text text;
	Sprite sprite;
	Texture texture;
	Wagon *next = nullptr;
	int result;
};

