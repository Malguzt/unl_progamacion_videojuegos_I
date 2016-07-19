#include "Game.h"
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
	blocks.checkHit(character.getArea());
}

void Game::drawGame()
{
    pWnd->draw(backgroundSprite);
	pWnd->draw(floorSprite);
    character.draw(*pWnd);
	blocks.draw(*pWnd);
}