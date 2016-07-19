#include "Character.h"

using namespace sf;

Character::Character()
{
    jumping = false;
    position = Vector2f(400, 500);
    texture.loadFromFile("img/lumberman.png");
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

Character::~Character(){}


void Character::draw(RenderWindow &gm)
{
    sprite.setPosition(position);
    gm.draw(sprite);
}

void Character::update()
{
    if (jumping) {
        if (position.y > 200) {
            position.y -= 5;
        } else {
            jumping = false;
        }
    } else {
        if(position.y < 500) {
            position.y += 7;
        }
    }
}

void Character::moveLeft()
{
    if(position.x > 0) {
        position.x -= 10;
    }
}

void Character::moveRight()
{
    if(position.x < 730) {
        position.x += 10;
    }
}

void Character::jump()
{
    jumping = true;
}