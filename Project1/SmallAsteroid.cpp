#include "SmallAsteroid.h"
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

SmallAsteroid::SmallAsteroid(sf::Vector2f position, Handler* handler, Vector2f speed, ID id, int idNumber):mass(1)
{
	this->position = position;
	this->handler = handler;
	this->id = id;

	float randXDir = (rand() % 100) /10;
	float randYDir = (rand() % 100 )/10;
	movement = Vector2f(randXDir/5-1, randYDir/5-1);

	movement = speed;
	
	if (!texture.loadFromFile("res/small_asteroid.png"))
	{
		std::cout << "Load failed" << std::endl;
		system("pause");
	}
	sprite.setTexture(texture);
}

void SmallAsteroid::Update() {
	if (toDestroy) return;
	position += movement;

	
	if (position.x < 0) position.x = SCREEN_WIDTH;
	else if (position.x > SCREEN_WIDTH) position.x = 0;
	
	if (position.y < 0) position.y = SCREEN_HEIGHT;
	else if (position.y > SCREEN_HEIGHT) position.y = 0;
}
void SmallAsteroid::Draw(sf::RenderWindow& windowRef)
{
	if (toDestroy) return;
	
	sprite.setPosition(GetCenter());
	sprite.setOrigin(22, 18);
	windowRef.draw(sprite);
	windowRef.draw(sprite);
}


