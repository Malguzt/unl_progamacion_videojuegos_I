#include "Game.h"
#include "Saw.h"
#define HEIGHT 700
#define WIDTH 1200
#define DIFICULT 0

Game::Game()
{
	backgroundTexture.loadFromFile("img/background.png");
	backgroundTexture.setRepeated(true);
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setTextureRect({ 0, 0, WIDTH, HEIGHT});

	float distance = HEIGHT / LEVELS;

	for (int i = 0; i < LEVELS; i++) {
		levels[i].setDificult(DIFICULT + i);
		levels[i].setWidth(WIDTH);
		levels[i].setY(HEIGHT - distance * i - 10);
	}

	pWnd = new RenderWindow(VideoMode(WIDTH, HEIGHT), "Cuidado que te sierra");
	pWnd->setFramerateLimit(60);

	character.setLevel(levels[level].getY());
}

Game::~Game()
{
	delete pWnd;
}

void Game::Go()
{
	Event evt;

	while (pWnd->isOpen())
	{

		while (pWnd->pollEvent(evt))
		{
			processEvent(evt);
		}

		pWnd->clear();
		updateGame();
		drawGame();
		pWnd->display();
	}
}

void Game::processEvent(Event &evt)
{
	switch (evt.type)
	{
	case Event::Closed:
		pWnd->close();
		break;
	case Event::KeyPressed:
		processKey(evt.key.code);
		break;
	}
}

void Game::processKey(int keyCode)
{
	if (Keyboard::isKeyPressed(Keyboard::Right)) character.moveRight();
	if (Keyboard::isKeyPressed(Keyboard::Left)) character.moveLeft();
	if (Keyboard::isKeyPressed(Keyboard::Up) && level < LEVELS - 1) character.setLevel(levels[++level].getY());
	// if(Keyboard::isKeyPressed(Keyboard::Down)) character.kneel();

	switch (keyCode)
	{
	case Keyboard::Escape:
		pWnd->close();
		break;
	}
}

void Game::updateGame()
{
	character.update();
}

void Game::drawGame()
{
	pWnd->draw(backgroundSprite);
	for each (Level level in levels)
	{
		level.draw(*pWnd);
	}
	character.draw(*pWnd);
}