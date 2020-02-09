#pragma once
#define BIGASTEROID_H
#include "GameObject.h"
#include "SFML/Graphics.hpp"
#include "Handler.h"


class Handler;

class BigAsteroid :public GameObject
{
public:

	float mass;
	BigAsteroid(sf::Vector2f position, Handler* handler, sf::Vector2f speed,ID id, int idNumber);
	void Update()override;
	void Draw(sf::RenderWindow& windowRef) override;
};

