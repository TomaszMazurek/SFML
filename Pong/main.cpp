#include <SFML/Graphics.hpp>
#include "Variables.h"
#include "Paddle.h"
#include "Ball.h"
#include <iostream>

using namespace sf;

void collision(Paddle& cpad, Ball& cball);
 
 
int main()
{
    Paddle paddle = Paddle(100, 10, 20, HEIGHT/2, 1);
    Paddle paddle2 = Paddle(100, 10, WIDTH-20, HEIGHT/2,2);
    Ball puck = Ball(10,WIDTH/2+10, HEIGHT/2+10);
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Pong!");
    window.setFramerateLimit(FRAMERATE);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();
        paddle.input();
        paddle2.input();
        puck.collides();
        //collision(paddle, puck);
        collision(paddle2, puck);
        puck.move();
        
        //window.draw(paddle.body);
        window.draw(paddle2.body);
        window.draw(puck.ball);
        
        window.display();
    }
 
    return 0;
}

void collision(Paddle& cpad, Ball& cball){
    if(cball.ball.getPosition().x == cpad.body.getPosition().x  
        && cball.ball.getPosition().y <= cpad.body.getPosition().y + cpad.body.getSize().y){
            cball.velocity.x *= -1;
            std::cout << "Hit!" << std::endl;
        }
}