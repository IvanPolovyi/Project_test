#include "BigAsteroid.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <math.h>
#include <vector>
#include "ID.h"
#include "Handler.h"
#include "Game.h"
#include <cstdlib>


using namespace std;
using namespace sf;

BigAsteroid::BigAsteroid(sf::Vector2f position, Handler* handler, Vector2f speed, ID id,int IdNumber) :mass(1)
{
	this->position = position;
	this->handler = handler;
	this->id = id;
	this->idNumber = IdNumber;
	radius = 32.0f;
	

	float randXDir = (rand() % 100) / 10;
	float randYDir = (rand() % 100) / 10;
	movement = Vector2f(randXDir / 5 - 1, randYDir / 5 - 1);
	movement = speed;
	if (!texture.loadFromFile("res/big_asteroid.png"))
	{
		std::cout << "Load failed" << std::endl;
		system("pause");
	}
	sprite.setTexture(texture);
}

void BigAsteroid::Update() {
	if(toDestroy) return;
	position += movement;

	if (position.x < 0) position.x = SCREEN_WIDTH;
	else if (position.x > SCREEN_WIDTH) position.x = 0;

	if (position.y < 0) position.y = SCREEN_HEIGHT;
	else if (position.y > SCREEN_HEIGHT) position.y = 0;
}
void BigAsteroid::Draw(sf::RenderWindow& windowRef)
{
	if (toDestroy) return;
	sprite.setPosition(GetCenter());
	sprite.setOrigin(34, 30);
	windowRef.draw(sprite);

	windowRef.draw(sprite);
}


