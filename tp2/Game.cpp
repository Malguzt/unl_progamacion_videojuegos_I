#include "Game.h"
#include "Saw.h"
#include <sstream>
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
		levels[i].setY(HEIGHT - distance * i - 10);
		levels[i].setWidth(WIDTH);
		levels[i].setDificult(DIFICULT + i);
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

	int i = 100;
	while (pWnd->isOpen())
	{
		while (pWnd->pollEvent(evt))
		{
			processEvent(evt);
		}

		pWnd->clear();
		if (true)
		{
			updateGame();
			drawGame();
		}
		else
		{
			Font font;
			font.loadFromFile("sixty.ttf");
			Text text;
			text.setFont(font);
			text.setColor(Color::Green);

			text.setCharacterSize(50);
			text.setPosition(300, 100);
			text.setString("Perdiste\n");

			pWnd->draw(text);
		}
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
	for (int i = 0; i < LEVELS; i++)
	{
		levels[i].moveSaw();
	}
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