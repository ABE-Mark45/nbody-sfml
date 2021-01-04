#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "RigidBody.h"
#include "CircleCollider.h"
#include "utils.h"


int main()
{
    float G = 1e4;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    window.setFramerateLimit(120);
    std::vector<RigidBody> bodies;
    /*
    * // Infinity example
    RigidBody a = RigidBody(1);
    a.setPosition(sf::Vector2f(0.97000436, -0.24308753));

    RigidBody b = RigidBody(1);
    b.setPosition(-sf::Vector2f(0.97000436, -0.24308753));

    RigidBody c = RigidBody(1);
    c.setPosition(sf::Vector2f(0, 0));
    c.velocity = sf::Vector2f(-0.93240737, -0.86473146);

    a.velocity = -0.5f * c.velocity;
    b.velocity = -0.5f * c.velocity;

    bodies.push_back(a);
    bodies.push_back(b);
    bodies.push_back(c);
    */


    float deltaTime = 0.01;
    
    while (window.isOpen())
    {
        sf::Event event;
        bool isMousePressed = false;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.mouseButton.button == sf::Mouse::Left && event.type == sf::Event::MouseButtonReleased)
            {
                RigidBody newRigidBody = RigidBody(rand()%20+2);
                sf::Vector2f pos = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                newRigidBody.setPosition(pos);
                //newRigidBody.velocity = sf::Vector2f(rand() % 100 - 50, rand() % 100 - 50);
                bodies.push_back(newRigidBody);
                break;
            }

        }


        window.clear();
        
        for (int i = 0; i < bodies.size(); i++)
        {
            bodies[i].acceleration = sf::Vector2f(0.0f, 0.0f);
            CircleCollider colliderA = CircleCollider(bodies[i]);
            for (int j = 0; j < bodies.size(); j++)
            {
                if (i == j)
                    continue;
                
                CircleCollider colliderB = CircleCollider(bodies[j]);
                if (colliderA.detectCollision(colliderB))
                {
                    colliderA.resolveCollision(colliderB);
                }
                
                sf::Vector2f r = bodies[j].getPosition() - bodies[i].getPosition();
                float sep = magnitude(r);
                r /= pow(sep, 3);
                bodies[i].acceleration += r*bodies[j].mass*G;
            }
        }
        sf::Vector2f COM_pos = sf::Vector2f(0, 0);
        for (int i = 0; i < bodies.size(); i++)
        {
            bodies[i].velocity += deltaTime * bodies[i].acceleration;
            bodies[i].setPosition(bodies[i].getPosition() + deltaTime * bodies[i].velocity);
        }


        for (RigidBody& body : bodies)
            body.draw(window);

        window.display();
    }

    return 0;
}