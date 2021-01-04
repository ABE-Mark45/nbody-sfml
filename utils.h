#pragma once
#include <SFML/Graphics.hpp>

float magnitude(sf::Vector2f vec);

float dotProduct(sf::Vector2f a, sf::Vector2f b);

void drawLines(sf::RenderWindow& window, sf::Vector2f a, sf::Vector2f b);