#pragma once
#define GAMEOBJECT_H
#include "ID.h"
#include "Handler.h"
//#ifndef GAMEOBJECT_H
#include "SFML/Graphics.hpp"

class GameObject
{
protected:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Handler* handler;
	sf::Vector2f position;
	sf::Vector2f movement;
	sf::Vector2f center;
	float radius;
	ID id;
	int idNumber;
	bool toDestroy;

	GameObject();
	virtual ~GameObject() = default;

	virtual void Update();
	virtual void Draw(sf::RenderWindow &windowRef);
	ID GetID();
	void setID(ID id);
	int getIdNumber();
	float GetRadius();
	sf::Vector2f GetMovement();
	void SetMovement(sf::Vector2f newMovement);
	sf::Vector2f GetCenter();
	void setIdNumber(int idNumber);
	void Destroy();
	bool CollisionDetection(GameObject &other);
	
}; 
//#endif

