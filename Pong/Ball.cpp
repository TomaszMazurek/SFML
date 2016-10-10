#include "Ball.h"
#include "Variables.h"

Ball::Ball(int size, int x, int y)
{
    this->size = size;
    this->x = x;
    this->y = y;
    velocity.x = 5;
    velocity.y = 5;
    ball.setRadius(size);
    ball.setPosition(sf::Vector2f(x,y));
   
}

void Ball::move()
{
    ball.move(velocity);
}

void Ball::collides(){
    if(ball.getPosition().x <= 0 || ball.getPosition().x >= WIDTH-20)
    {
        velocity.x *= -1;
    }
    if(ball.getPosition().y <= 0 || ball.getPosition().y >= HEIGHT-20)
    {
        velocity.y *= -1;
    }
}