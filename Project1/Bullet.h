#pragma once
#define BULLET_H
#include "GameObject.h"
#include "SFML/Graphics.hpp"
#include "Handler.h"



class Bullet :public GameObject
{
public:

	
	Bullet(sf::Vector2f position, Handler* handler, sf::Vector2f speed, ID id, int idNumber);
	~Bullet();
	
	void Update()override;
	void Draw(sf::RenderWindow& windowRef) override;

};

