#include "Game.h"
#include <sstream>
#define HEIGHT 700
#define WIDTH 1200

using namespace sf;
using namespace std;

Game::Game()
{
	backgroundTexture.loadFromFile("img/background.png");
	backgroundTexture.setRepeated(true);
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setTextureRect({ 0, 0, WIDTH, HEIGHT});

	float distance = HEIGHT / LEVELS;

	for (int i = 0; i < LEVELS; i++) {
		levels[i].setWidth(WIDTH);
		levels[i].setY(HEIGHT - distance * i - 10);
	}

	stationTexture.loadFromFile("img/station.png");
	stationSprite.setTexture(stationTexture);
	stationSprite.setPosition(WIDTH - 150, levels[0].getY() - 60);
	stationRect = FloatRect(stationSprite.getPosition(), Vector2f(37, 80));

	pWnd = new RenderWindow(VideoMode(WIDTH, HEIGHT), "Tren muggle");
	pWnd->setFramerateLimit(60);

	train.setPosition(Vector2f(1, levels[level].getY()));
}

Game::~Game()
{
	delete pWnd;
}

void Game::Go()
{
	Event evt;

	int i = 100;
	while (pWnd->isOpen())
	{
		while (pWnd->pollEvent(evt))
		{
			processEvent(evt);
		}

		pWnd->clear();
		if (lost)
		{
			level = 0;
			train.setPosition(Vector2f(WIDTH / 2, levels[level].getY()));
			lost = false;
		}
		else if (win)
		{
			text.setColor(Color::Green);
			text.setString("Ganaste\n");
		}
		else
		{
			updateGame();
			drawGame();
		}
		pWnd->draw(text);
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
	switch (keyCode)
	{
	case Keyboard::Escape:
		pWnd->close();
		break;
	}
}

void Game::updateGame()
{
	if (!train.inScreen(WIDTH)) {
		train.setPosition(Vector2f(0, levels[--level].getY()));
	}
	train.update();
	//lost = levels[level].checkCollision(train.getArea());

	win = stationRect.intersects(train.getArea());
}

void Game::drawGame()
{
	pWnd->draw(backgroundSprite);
	pWnd->draw(stationSprite);
	for (int i = 0; i < LEVELS; ++i)
	{
		levels[i].draw(*pWnd);
	}
	train.draw(*pWnd);
}