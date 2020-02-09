#pragma once
#define SMALLASTEROID_H
#include "GameObject.h"
#include "SFML/Graphics.hpp"
#include "Handler.h"



class SmallAsteroid :public GameObject
{
public:

	float mass;
	
	SmallAsteroid(sf::Vector2f position, Handler* handler, sf::Vector2f speed, ID id, int IdNumber);
	void Update()override;
	void Draw(sf::RenderWindow& windowRef) override;

};

