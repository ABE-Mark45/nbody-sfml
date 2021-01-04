#pragma once
#include <SFML/Graphics.hpp>
#include "RigidBody.h"

class CircleCollider
{
private:
	RigidBody& body;

public:
	CircleCollider(RigidBody& body);
	RigidBody& getRigidBody();
	float getRadius();
	bool detectCollision(CircleCollider& B);
	void resolveCollision(CircleCollider& B);
};

