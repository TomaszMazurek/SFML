#include "Game.h"

Game::Game(): mWindow(sf::VideoMode(800,600), "RiverRaid"),mPlayer()
{
    mPlayer.setRadius(40.f);
    mPlayer.setPosition(100.f,100.f);
    mPlayer.setFillColor(sf::Color::Cyan);
}

void Game::run()
{
    while(mWindow.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
            case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
        }
        
    }
}

void Game::update()
{
    sf::Vector2f movement(0.f, 0.f);
    if(Game::mIsMovingUp)
        movement.y -= 1.f;
    if(Game::mIsMovingDown)
        movement.y += 1.f;
    if(Game::mIsMovingLeft)
        movement.x -= 1.f;
    if(Game::mIsMovingRight)
        movement.x += 1.f;
        mPlayer.move(movement);
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::W)
        Game::mIsMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        Game::mIsMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        Game::mIsMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        Game::mIsMovingRight = isPressed;
}