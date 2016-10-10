#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>

class Ball
{
public:
    sf::CircleShape ball;
    int size;
    int x;
    int y;
    Ball(int size, int x, int y);
    sf::Vector2f velocity;
    void move();
    void collides();

};

#endif // BALL_H
