#include "Character.h"

using namespace sf;

Character::Character()
{
	position = Vector2f(400, 500);
	texture.loadFromFile("img/character.png");
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
	position.y = y - 64;
}