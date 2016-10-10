#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>


class Paddle{
public:
    
    sf::RectangleShape body;
    float height;
    float width;
    int x;
    int y;
    int player;
    Paddle(int height, int width, int x, int y, int player);
    Paddle(sf::RectangleShape);
    
    void moveUp();
    void moveDown();
    void input();
};

#endif // PADDLE_H
