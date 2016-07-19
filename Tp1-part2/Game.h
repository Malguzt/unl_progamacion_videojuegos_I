#ifndef GAME_H
#define GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Blocks.h"

using namespace sf;
using namespace std;

class Game
{
    public:
        Game();
        virtual ~Game();
        void Go();
    private:
		Blocks blocks;
        RenderWindow *pWnd;
        Character character;
        void processEvent(Event &evt);
        void drawGame();
        void updateGame();
        void processKey(int keyCode);
		Texture backgroundTexture;
		Sprite backgroundSprite;
		Texture floorTexture;
		Sprite floorSprite;
};

#endif // GAME_H
