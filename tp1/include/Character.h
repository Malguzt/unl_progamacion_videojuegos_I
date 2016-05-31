#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Character
{
    public:
        Character();
        virtual ~Character();
        void update();
        void draw(RenderWindow &gm);
        void moveRight();
        void moveLeft();
        void jump();
    protected:
    private:
        bool jumping;
        Vector2f position;
        Sprite sprite;
        Texture texture;
        void changePosition();
};

#endif // CHARACTER_H
