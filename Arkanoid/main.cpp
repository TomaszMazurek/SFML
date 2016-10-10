#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "Ball.h"
#include "Paddle.h"
#include <Brick.h>

using namespace sf;

template<class T1, class T2> bool isIntersecting(T1& mA, T2& mB)
{
    return mA.right() >= mB.left() && mA.left() <= mB.right()
            && mA.bottom() >= mB.top() && mA.top() <= mB.bottom();
}

void testCollision(Paddle& mPaddle, Ball& mBall);


int main()
{
    Ball ball {windowWidth/2,windowHeight/2};
    Paddle paddle {windowWidth/2, windowHeight-50};
    
    RenderWindow window{{windowWidth, windowHeight}, "ArcanoidClone"};
    window.setFramerateLimit(60);
    
    while(true)
    {
        window.clear();
        if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) break;
        
        ball.update();
        paddle.update();
        
        window.draw(ball.shape);
        window.draw(paddle.shape);
        testCollision(paddle,ball);
        window.display();
    }
    
	return 0;
}

void testCollision(Paddle& mPaddle, Ball& mBall)
{
    if(!isIntersecting(mPaddle, mBall)) return;
    mBall.velocity.y = -ballVelocity;
    
    if(mBall.x() < mPaddle.x()) mBall.velocity.x = -ballVelocity;
    else mBall.velocity.x = ballVelocity;
    
}
