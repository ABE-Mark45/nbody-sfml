#include "RigidBody.h"
RigidBody::RigidBody()
{

}

RigidBody::RigidBody(float mass): mass(mass)
{
    this->radius = mass*1.5;
    shape = sf::CircleShape(this->radius);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(radius, radius);
    acceleration = sf::Vector2f(0, 0);
}

sf::Vector2f RigidBody::getPosition()
{
    return shape.getPosition();
}

void RigidBody::setPosition(sf::Vector2f pos)
{
    shape.setPosition(pos);
}

void RigidBody::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

sf::Vector2f RigidBody::getVelocity()
{
    return velocity;
}

void RigidBody::setVelocity(sf::Vector2f newVelocity)
{
    velocity = newVelocity;
}

