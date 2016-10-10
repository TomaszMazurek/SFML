#ifndef BRICK_H
#define BRICK_H
#include <SFML/Graphics.hpp>

struct Brick
{
    
    sf::RectangleShape shape;
    
    bool destroyed;
    
    
    Brick(float mX, float mY);
    

};

#endif // BRICK_H
