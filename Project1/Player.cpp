#include "SFML/Graphics.hpp"
#include <iostream>
#include "Player.h"
#include "ID.h"
#include "Handler.h"
#include "Bullet.h"

using namespace std;
using namespace sf;

Player::Player(sf::Vector2f position, Handler* handler,  ID id, int IdNumber, sf::RenderWindow& windowRef): windowRef(windowRef)
{
	this->position = position;
	this->handler = handler;
	this->id = id;
	this->idNumber = IdNumber;
	movement = Vector2f(0.0f, 0.0f);
	radius = 22;

	if (!texture.loadFromFile("res/spaceship.png"))
	{
		std::cout << "Load failed" << std::endl;
		system("pause");
	}
	sprite.setTexture(texture);
	
}

void Player::Update() {
	

	if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
		movement.x = -maxVelocity;
	else if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
		movement.x = maxVelocity;
	if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
		movement.y = -maxVelocity;
	else if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
		movement.y = maxVelocity;

	if (movement.x > 0) movement.x -= deceleration;
	if (movement.x < 0) movement.x += deceleration;
	if (movement.y > 0) movement.y -= deceleration;
	if (movement.y < 0) movement.y += deceleration;

	movement.x = Clamp(movement.x, -maxVelocity, maxVelocity);
	movement.y = Clamp(movement.y, -maxVelocity, maxVelocity);

	Vector2f mousePosWindow = Vector2f(Mouse::getPosition(windowRef));
	Vector2f aimDir = mousePosWindow - GetCenter();
	Vector2f aimDirNorm = aimDir / sqrt(aimDir.x * aimDir.x + aimDir.y * aimDir.y);

	position += movement;
	
	/*for (auto& i : handler->asteroids)
	{
		if (CollisionDetection(*i))
			cout << "Collision!" << endl;
	}*/
}
void Player::Draw(sf::RenderWindow& windowRef) {
	
	sprite.setPosition(GetCenter());
	//shape.setFillColor(color);
	sf::Vector2f mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(windowRef));
	float angle = atan2(GetCenter().y -mousePosWindow.y, GetCenter().x -mousePosWindow.x);
	sprite.setOrigin(22, 26);
	sprite.setRotation(angle*180 / 3.14159265359-90);
	
	windowRef.draw(sprite);

}




float Player::Clamp(float value, float min, float max)
{
	if (value >= max) return max;
	else if (value <= min) return min;
	else if (abs(value) < 0.001) return 0;
	else return value;
}


