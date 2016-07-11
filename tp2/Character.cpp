#include "Character.h"

using namespace sf;

Character::Character()
{
	texture.loadFromFile("img/lumberman.png");
	sprite.setTexture(texture);
	sprite.setPosition(position);
}

Character::~Character() {}

void Character::draw(RenderWindow &gm)
{
	sprite.setPosition(position);
	gm.draw(sprite);
}

void Character::update()
{
}

void Character::moveLeft()
{
	if (position.x > 0) {
		position.x -= 30;
	}
}

void Character::moveRight()
{
	if (position.x < 730) {
		position.x += 30;
	}
}

void Character::setLevel(float y)
{
	setPosition(Vector2f(position.x, y));
}

FloatRect Character::getArea()
{
	return FloatRect(position, Vector2f(70, 68));
}

void Character::setPosition(Vector2f value)
{
	position = value - Vector2f(0, 70);
}
