#include "CircleCollider.h"
#include "RigidBody.h"
#include "utils.h"

CircleCollider::CircleCollider(RigidBody& body) : body(body) {}

RigidBody& CircleCollider::getRigidBody()
{
	return body;
}


float CircleCollider::getRadius()
{
	return body.radius;
}

bool CircleCollider::detectCollision(CircleCollider& B)
{
	sf::Vector2f A_pos = body.getPosition();
	float A_radius = getRadius();
	
	sf::Vector2f B_pos = B.getRigidBody().getPosition();
	float B_radius = B.getRadius();

	sf::Vector2f delta = B_pos - A_pos;

	float intersect = delta.x * delta.x + delta.y * delta.y;
	float radiiSumSquared = (A_radius + B_radius) * (A_radius + B_radius);
	if (intersect < radiiSumSquared)
		return true;

	return false;
}

void CircleCollider::resolveCollision(CircleCollider& B)
{
	sf::Vector2f A_pos = body.getPosition();
	sf::Vector2f B_pos = B.getRigidBody().getPosition();

	float radiusSum = getRadius() + B.getRadius();

	sf::Vector2f delta = B_pos - A_pos;
	float mag = magnitude(delta);
	delta /= mag;
	float offset = radiusSum - mag;
	
	sf::Vector2f normalA_old = delta * dotProduct(delta, body.velocity);
	sf::Vector2f normalB_old = delta * dotProduct(delta, B.body.velocity);

	sf::Vector2f tangentA = body.velocity - normalA_old;
	sf::Vector2f tangentB = B.body.velocity - normalB_old;

	sf::Vector2f normalA_new = (body.mass - B.body.mass) / (body.mass + B.body.mass) * normalA_old + 2 * B.body.mass / (body.mass + B.body.mass) * normalB_old;
	sf::Vector2f normalB_new = 2 * body.mass / (body.mass + B.body.mass) * normalA_old + (-body.mass + B.body.mass) / (body.mass + B.body.mass) * normalB_old;

	body.velocity = normalA_new + tangentA;
	B.body.velocity = normalB_new + tangentB;
	body.setPosition(body.getPosition() - delta * offset * (body.radius / radiusSum));
	B.body.setPosition(B.body.getPosition() + delta * offset * (B.body.radius / radiusSum));
}