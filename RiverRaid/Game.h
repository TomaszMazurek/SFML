#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Game
{
    sf::RenderWindow mWindow;
    sf::CircleShape mPlayer;
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingLeft;
    bool mIsMovingRight;
    
    void    processEvents();
    void    update();
    void    render();
    void    handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
public:
            Game();
    void    run();
};

#endif // GAME_H
