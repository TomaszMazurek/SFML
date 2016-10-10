#include "Paddle.h"
#include "Variables.h"
#include <iostream>

Paddle::Paddle(int height, int width, int x, int y, int player)
{
    this->height = height;
    this->width = width;
    this->x = x;
    this->y = y;
    this->player = player;
    body.setPosition(this->x, this->y);
    body.setSize(sf::Vector2f(this->width, this->height));
}


void Paddle::input()
{
    if(player == 1){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        if(DEBUG){
            std::cout<<body.getPosition().y<<std::endl;
            body.move(sf::Vector2f(0,-VELOCITY));
            
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        if(DEBUG){
            std::cout<<body.getPosition().y<<std::endl;
            body.move(sf::Vector2f(0,VELOCITY));
        }
        
    }
    if(player == 2){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        if(DEBUG){
            std::cout<<body.getPosition().y<<std::endl;
            body.move(sf::Vector2f(0,-VELOCITY));
            
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        if(DEBUG){
            std::cout<<body.getPosition().y<<std::endl;
            body.move(sf::Vector2f(0,VELOCITY));
        }
        
    }
}



