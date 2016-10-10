#include "Paddle.h"
#include "Ball.h"


Paddle::Paddle(float mX, float mY)
{
    shape.setPosition(mX, mY);
    shape.setSize({paddleWidth, paddleHeight});
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(paddleWidth/2.f, paddleHeight/2.f);
}

void Paddle::update()
{
    shape.move(velocity);
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)
        && left() > 0) velocity.x = -paddleVelocity;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
        && right() < windowWidth) velocity.x = paddleVelocity;
    else velocity.x = 0;
}

float Paddle::x()       {return shape.getPosition().x;}
float Paddle::y()       {return shape.getPosition().y;}
float Paddle::left()    {return x() - shape.getSize().x/2.f ;}
float Paddle::right()   {return x() + shape.getSize().x/2.f ;}
float Paddle::top()     {return y() - shape.getSize().y/2.f ;}
float Paddle::bottom()  {return y() + shape.getSize().y/2.f ;}


