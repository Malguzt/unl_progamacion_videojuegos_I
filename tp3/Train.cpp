#include "Train.h"
#include "Wagon.h"

using namespace sf;

Train::Train()
{
	texture.loadFromFile("img/engine.png");
	sprite.setTexture(texture);
	sprite.setPosition(position);
	for (int i = 0; i < 2; ++i) {
		Wagon *newWagon = new Wagon();
		wagons.add(newWagon);
	}
}

Train::~Train() {
}

void Train::draw(RenderWindow &gm)
{
	sprite.setPosition(position);
	wagons.draw(gm);
	gm.draw(sprite);
}

void Train::update()
{
	moveX(3);
	wagons.setPosition(position.x, position.y);
}

void Train::setLevel(float y)
{
	setPosition(Vector2f(position.x, y));
}

FloatRect Train::getArea()
{
	return FloatRect(position, Vector2f(70, 68));
}

void Train::setPosition(Vector2f value)
{
	position = value - Vector2f(0, 40);
	wagons.setPosition(position.x, position.y);
}

bool Train::inScreen(int width)
{
	bool inScreen = position.x > 0 && position.x < width + texture.getSize().x;
	return inScreen = inScreen || wagons.inScreen(width);
}

void Train::add(Wagon * wagon)
{
	wagons.add(wagon);
	wagons.sortWagons();
}

void Train::release()
{
	wagons.release();
}

void Train::moveX(float x)
{
	position = Vector2f(position.x + x, position.y);
}
