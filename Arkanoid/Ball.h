#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>

constexpr float ballRadius{10.f}, ballVelocity{8.f};
constexpr int windowWidth{800}, windowHeight{600};

class Ball
{
public:
    sf::Vector2f velocity{-ballVelocity, -ballVelocity};
    sf::CircleShape shape;
    Ball(float mX, float mY);
    void update();
    float x();
    float y();
    float left();
    float right();
    float top();
    float bottom();
};

#endif // BALL_H
