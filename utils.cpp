#include "utils.h"

float magnitude(sf::Vector2f vec)
{
	return sqrt(vec.x * vec.x + vec.y * vec.y);
}


float dotProduct(sf::Vector2f a, sf::Vector2f b)
{
	return a.x * b.x + a.y * b.y;
}


void drawLines(sf::RenderWindow& window, sf::Vector2f a, sf::Vector2f b)
{
	//window.draw({ sf::Vertex(a), sf::Vertex(b) }, 2, sf::Lines);
}