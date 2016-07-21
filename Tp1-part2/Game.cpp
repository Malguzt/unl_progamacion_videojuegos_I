#include "Game.h"
#include <sstream>
#define HEIGHT 600
#define WIDTH 800
Game::Game()
{
    backgroundTexture.loadFromFile("img/background.png");
    backgroundTexture.setRepeated(true);
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setTextureRect({ 0, 0, WIDTH, HEIGHT });

	floorTexture.loadFromFile("img/floor.jpg");
	floorTexture.setRepeated(true);
	floorSprite.setTexture(floorTexture);
	floorSprite.setPosition(0, HEIGHT - 20);
	floorSprite.setTextureRect({ 0, 0, WIDTH, 20 });

    pWnd = new RenderWindow(VideoMode(WIDTH, HEIGHT), "A los piedrazos");
    pWnd->setFramerateLimit(60);

	font.loadFromFile("sixty.ttf");
	text.setFont(font);
	text.setCharacterSize(50);
	text.setPosition(20, 20);
}

Game::~Game()
{
    delete pWnd;
}

void Game::Go()
{
    Event evt;

    while(pWnd->isOpen())
    {

        while (pWnd->pollEvent(evt))
        {
            processEvent(evt);
        }

        pWnd->clear();
		if (clock.getElapsedTime().asSeconds() < time)
		{
			updateGame();
		}
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
    if(Keyboard::isKeyPressed(Keyboard::Right)) character.moveRight();
    if(Keyboard::isKeyPressed(Keyboard::Left)) character.moveLeft();
    if(Keyboard::isKeyPressed(Keyboard::Up)) character.jump();

    switch(keyCode)
    {
        case Keyboard::Escape:
            pWnd->close();
            break;
    }
}

void Game::updateGame()
{
    character.update();
	if (!blocks.checkHit(character.getArea())) {
		time -= 10;
	}
}

void Game::drawGame()
{
	bool inTime = clock.getElapsedTime().asSeconds() < time;
    pWnd->draw(backgroundSprite);
	pWnd->draw(floorSprite);
    character.draw(*pWnd);

	blocks.draw(*pWnd, !inTime);
	if (inTime)
	{
		text.setColor(Color::White);
		ostringstream ss;
		ss << time - (int)clock.getElapsedTime().asSeconds();
		text.setString("Tiempo: 00:" + ss.str());
		pWnd->draw(text);
	}
}