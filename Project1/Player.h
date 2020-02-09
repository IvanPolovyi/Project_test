#pragma once
//#ifndef HANDLER_H
#define PLAYER_H
#include "GameObject.h"
#include "Handler.h"

class Player : public GameObject
{
public:

	float maxVelocity = 7.0f;
	float deceleration = 0.2f;
	float acceleration = 1.5f;

	sf::Vector2f playerCenter;
	sf::RenderWindow center;
	sf::RenderWindow& windowRef;

	Player(sf::Vector2f position, Handler* handler, ID id, int IdNumber, sf::RenderWindow& windowRef);

	void Update()override;
	void Draw(sf::RenderWindow &windowRef) override;
	static float Clamp(float value, float min, float max);

};

//#endif