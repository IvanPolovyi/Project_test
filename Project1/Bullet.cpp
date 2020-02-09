#include "Bullet.h"
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

Bullet::Bullet(sf::Vector2f position, Handler* handler, Vector2f speed, ID id, int IdNumber)
{
	this->position = position;
	this->handler = handler;
	this->id = id;
	this->idNumber = IdNumber;
	toDestroy = false;

	if (!texture.loadFromFile("res/bullet.png"))
	{
		std::cout << "Load failed" << std::endl;
		system("pause");
	}
	sprite.setTexture(texture);

	movement = speed;
	cout << speed.x << " " << speed.y << endl;
	cout << handler->bullets.size() << endl;
}

Bullet::~Bullet() = default;;

void Bullet::Update() {
	if (toDestroy) return;
	
	position += movement;
	if (position.x < 0 || position.x > SCREEN_WIDTH || position.y < 0 || position.y > SCREEN_HEIGHT) {
		Destroy();
	}

}
void Bullet::Draw(sf::RenderWindow& windowRef)
{
	if (toDestroy) return;
	
	sprite.setPosition(position);
	sprite.setOrigin(6, 6);
	windowRef.draw(sprite);

	windowRef.draw(sprite);
}
