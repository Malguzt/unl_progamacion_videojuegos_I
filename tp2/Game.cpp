#include "Game.h"
#include "Saw.h"
#include "ListLevel.h"
#include "PoolLevel.h"
#include <sstream>
#define HEIGHT 700
#define WIDTH 1200
#define DIFICULT 0

Game::Game()
{
	font.loadFromFile("sixty.ttf");
	text.setFont(font);
	text.setCharacterSize(50);
	text.setPosition(300, 100);

	backgroundTexture.loadFromFile("img/background.png");
	backgroundTexture.setRepeated(true);
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setTextureRect({ 0, 0, WIDTH, HEIGHT});

	float distance = HEIGHT / LEVELS;

	for (int i = 0; i < LEVELS; i++) {
		if (i % 2 == 0)
		{
			levels[i] = new ListLevel();
		}
		else
		{
			levels[i] = new PoolLevel();
		}
	
	levels			[i]->setWidth(WIDTH);
		levels[i]->setY(HEIGHT - distance * i - 10);
		levels[i]->setDificult(DIFICULT + i);
	}

	doorTexture.loadFromFile("img/door.png");
	doorSprite.setTexture(doorTexture);
	doorSprite.setPosition(WIDTH / 2 - 37, levels[LEVELS - 1]->getY() - 80);
	doorRect = FloatRect(doorSprite.getPosition(), Vector2f(37, 80));

	pWnd = new RenderWindow(VideoMode(WIDTH, HEIGHT), "Cuidado que te sierra");
	pWnd->setFramerateLimit(60);

	character.setLevel(levels[level]->getY());
}

Game::~Game()
{
	delete pWnd;
	for (int i = 0; i < LEVELS; ++i)
	{
		delete levels[i];
	}
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
			text.setColor(Color::Red);
			text.setString("Perdiste\n");
			pWnd->draw(text);
		}
		else if (win)
		{
			text.setColor(Color::Green);
			text.setString("Ganaste\n");
			pWnd->draw(text);
		}
		else
		{
			updateGame();
			drawGame();
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
	if (Keyboard::isKeyPressed(Keyboard::Up) && level < LEVELS - 1) character.setLevel(levels[++level]->getY());

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
		levels[i]->moveSaw();
	}
	lost = levels[level]->checkCollision(character.getArea());

	win = doorRect.intersects(character.getArea());
}

void Game::drawGame()
{
	pWnd->draw(backgroundSprite);
	pWnd->draw(doorSprite);
	for (int i = 0; i < LEVELS; ++i)
	{
		levels[i]->draw(*pWnd);
	}
	character.draw(*pWnd);
}