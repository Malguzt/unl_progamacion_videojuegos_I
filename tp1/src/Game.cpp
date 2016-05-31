#include "Game.h"
Game::Game()
{
    backgroundTexture.loadFromFile("img/background.png");
    backgroundTexture.setRepeated(true);
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setTextureRect({ 0, 0, 800, 600 });

    pWnd = new RenderWindow(VideoMode(800, 600), "A los piedrazos");
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
    // if(Keyboard::isKeyPressed(Keyboard::Down)) character.kneel();

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
}

void Game::drawGame()
{
    pWnd->draw(backgroundSprite);
    character.draw(*pWnd);
}