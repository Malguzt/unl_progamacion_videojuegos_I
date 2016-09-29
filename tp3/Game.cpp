#include "Game.h"
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

	modal.setRect(FloatRect(WIDTH/2, HEIGHT/2, WIDTH/4, HEIGHT/4));
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
		if (errors > 2)
		{
			modal.draw(*pWnd, "Perdiste\n");
		}
		else if (win)
		{
			modal.draw(*pWnd, "Ganaste\n");
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
	switch (keyCode)
	{
	case Keyboard::Escape:
		pWnd->close();
		break;
	case Keyboard::Num0:
	case Keyboard::Numpad0:
		input << "0";
		break;
	case Keyboard::Num1:
	case Keyboard::Numpad1:
		input << "1";
		break;
	case Keyboard::Num2:
	case Keyboard::Numpad2:
		input << "2";
		break;
	case Keyboard::Num3:
	case Keyboard::Numpad3:
		input << "3";
		break;
	case Keyboard::Num4:
	case Keyboard::Numpad4:
		input << "4";
		break;
	case Keyboard::Num5:
	case Keyboard::Numpad5:
		input << "5";
		break;
	case Keyboard::Num6:
	case Keyboard::Numpad6:
		input << "6";
		break;
	case Keyboard::Num7:
	case Keyboard::Numpad7:
		input << "7";
		break;
	case Keyboard::Num8:
	case Keyboard::Numpad8:
		input << "8";
		break;
	case Keyboard::Num9:
	case Keyboard::Numpad9:
		input << "9";
		break;
	}
}

void Game::updateGame()
{
	if (!train.inScreen(WIDTH)) {
		train.setPosition(Vector2f(0, levels[--level].getY()));
	}
	train.update();
	if (levels[level].checkCollision(train.getArea())) {
		Event evt;
		stringstream sum;
		input.str("");
		clock.restart();
		drawGame();
		int wagonNumber = levels[level].getWagonNumber();
		int a = rand() % wagonNumber;
		int b = rand() % (wagonNumber - a);
		while (clock.getElapsedTime().asSeconds() < 3 && input.str() != to_string(wagonNumber))
		{
			sum.str("");
			sum << to_string(a) << '+' << to_string(b) << "+" << to_string(wagonNumber - a - b) << "= " << input.str();
			modal.draw(*pWnd, sum.str());
			pWnd->display();
			while (pWnd->pollEvent(evt))
			{
				processEvent(evt);
			}
		}
		if (input.str() == to_string(wagonNumber)) {
			train.add(levels[level].takeTheWagon());
		}
		else {
			errors++;
			levels[level].takeTheWagon();
			train.release();
		}
	}

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