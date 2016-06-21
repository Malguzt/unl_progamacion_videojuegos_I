#include "Game.h"
#define HEIGHT 600
#define WIDTH 800

Game::Game()
{
	backgroundTexture.loadFromFile("img/background.png");
	floorTexture.loadFromFile("img/floor.jpg");
	floorTexture.setRepeated(true);
	backgroundTexture.setRepeated(true);
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setTextureRect({ 0, 0, WIDTH, HEIGHT});

	float distance = HEIGHT / LEVELS;

	for (int i = 0; i < LEVELS; i++) {
		levels[i] = HEIGHT - distance * i - 10;
		floorsSprites[i].setTexture(floorTexture);
		floorsSprites[i].setTextureRect({ 0, i*5, WIDTH, 10});
		floorsSprites[i].setPosition(0, levels[i]);
	}

	pWnd = new RenderWindow(VideoMode(WIDTH, HEIGHT), "A los piedrazos");
	pWnd->setFramerateLimit(60);

	character.setLevel(levels[level]);
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
	if (Keyboard::isKeyPressed(Keyboard::Up)) character.setLevel(levels[++level]);
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
	for each (Sprite floor in floorsSprites)
	{
		pWnd->draw(floor);
	}
	character.draw(*pWnd);
}