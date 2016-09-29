#ifndef GAME_H
#define GAME_H
#define LEVELS 7

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>
#include "Train.h"
#include "Level.h"
#include "Modal.h"

using namespace sf;
using namespace std;

class Game
{
public:
	Game();
	virtual ~Game();
	void Go();
private:
	bool win = false;
	int errors = 0;
	RenderWindow *pWnd;
	Train train;
	void processEvent(Event &evt);
	void drawGame();
	void updateGame();
	void processKey(int keyCode);
	Texture stationTexture;
	Sprite stationSprite;
	FloatRect stationRect;
	Texture backgroundTexture;
	Sprite backgroundSprite;
	Level levels[LEVELS];
	int level = LEVELS - 1;
	Modal modal;
	Clock clock;
	stringstream input;
};

#endif // GAME_H
