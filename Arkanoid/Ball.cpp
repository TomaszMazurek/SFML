#include "Ball.h"


Ball::Ball(float mX, float mY)
{
    shape.setPosition(mX, mY);
    shape.setRadius(ballRadius);
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(ballRadius, ballRadius);
}

void Ball::update()
{
    shape.move(velocity);
    if(left() < 0) velocity.x = ballVelocity;
    else if(right() > windowWidth) velocity.x = -ballVelocity;
    
    if(top() < 0) velocity.y = ballVelocity;
    else if(bottom() > windowHeight) velocity.y = -ballVelocity;
}

float Ball::x()   {return shape.getPosition().x;}
float Ball::y()   {return shape.getPosition().y;}
float Ball::left()   {return x() - shape.getRadius() ;}
float Ball::right()   {return x() + shape.getRadius() ;}
float Ball::top()   {return y() - shape.getRadius() ;}
float Ball::bottom()   {return y() + shape.getRadius() ;}
