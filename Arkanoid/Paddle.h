#ifndef PADDLE_H
#define PADDLE_H
#include <SFML/Graphics.hpp>


constexpr float paddleWidth{60.f}, paddleHeight{20.f}, paddleVelocity{6.f};


class Paddle
{
public:
    sf::RectangleShape shape;    
    sf::Vector2f velocity;
    Paddle(float mX, float mY);
    void update();
    float x();
    float y();
    float left();
    float right();
    float top();
    float bottom();
};

#endif // PADDLE_H
