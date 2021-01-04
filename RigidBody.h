#pragma once
#include <SFML/Graphics.hpp>
class RigidBody
{
public:
    sf::CircleShape shape;
    sf::Vector2f velocity, acceleration;
    float mass;
    float radius;

    RigidBody();

    RigidBody(float mass);

    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f pos);
    void draw(sf::RenderWindow& window);
    sf::Vector2f getVelocity();
    void setVelocity(sf::Vector2f newVelocity);
};
