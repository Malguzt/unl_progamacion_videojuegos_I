#ifndef GAME_H
#define GAME_H
#define LEVELS 6

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Level.h"

using namespace sf;
using namespace std;

class Game
{
public:
	Game();
	virtual ~Game();
	void Go();
private:
	RenderWindow *pWnd;
	Character character;
	void processEvent(Event &evt);
	void drawGame();
	void updateGame();
	void processKey(int keyCode);
	Texture backgroundTexture;
	Sprite backgroundSprite;
	Level levels[LEVELS];
	int level = 0;
};

#endif // GAME_H
