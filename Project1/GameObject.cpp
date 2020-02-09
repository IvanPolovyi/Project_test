#include "SFML/Graphics.hpp"
#include <iostream>
#include <math.h>
#include <vector>
#include "GameObject.h"
#include "ID.h"


using namespace std;
using namespace sf;

GameObject::GameObject() {
	
}
void GameObject::Update() {};
void GameObject::Draw(sf::RenderWindow& windowRef) {};
void GameObject::Destroy()
{
	toDestroy = true;
	setID(ID::Destroyable);
};

ID GameObject::GetID()
{
	return id;
}
void GameObject::setID(ID id)
{
	this->id = id;
}
int GameObject::getIdNumber()
{
	return idNumber;

}
float GameObject::GetRadius()
{
	return this->radius;
}
sf::Vector2f GameObject::GetMovement()
{
	return this->movement;
}
void GameObject::setIdNumber(int idNumber)
{
	this->idNumber = idNumber;
}
void GameObject::SetMovement(sf::Vector2f newMovement)
{
	this->movement = newMovement;
}
sf::Vector2f GameObject::GetCenter()
{
	return {position.x + radius, position.y + radius};
}
bool GameObject::CollisionDetection(GameObject &other)
{
	sf::Vector2f otherCenter = other.GetCenter();
	float otherRadius = other.GetRadius();
	sf::Vector2f thisCenter = GetCenter();
	float thisRadius = GetRadius();

	sf::Vector2f vec = otherCenter - thisCenter;
	float distance = sqrt(vec.x * vec.x + vec.y * vec.y);

	if (GetID() == ID::Player) {
		if (distance <= thisRadius + otherRadius) {
			cout << distance << endl;
			return  true;
		}
	}
	/*else if(GetID()==ID::BigAsteroid || GetID() == ID::SmallAsteroid)
	{
		float m1 = 1;
		float m2 = 1;
		sf::Vector2f v1;
		sf::Vector2f v2;
		sf::Vector2f u1 = other.GetMovement();//sqrt(other.GetMovement().x * other.GetMovement().x + other.GetMovement().y* other.GetMovement().y);
		sf::Vector2f u2 = GetMovement();//  sqrt(GetMovement().x * GetMovement().x + GetMovement().y * GetMovement().y);
		sf::Vector2f x1 = otherCenter;
		sf::Vector2f x2 = thisCenter;
		
		if (distance <= thisRadius + otherRadius) {
			float absl1 = pow(abs((x1 - x2).x * (x1 - x2).x + (x1 - x2).y + (x1 - x2).y),2);
			Vector2f prod1 = (2 * m2 / (m1 + m2)) * ((u1 - u2).x *(x1 - x2).x) / absl1*(x1-x2);
			v1 = v1 - prod1;

			float absl2 = pow(abs((x2 - x1).x * (x2 - x1).x + (x2 - x1).y + (x2 - x1).y), 2);
			Vector2f prod2 = (2 * m1 / (m1 + m2)) * ((u2 - u1).x * (x2 - x1).x) / absl2 * (x2 - x1);
			v2 = v2 - prod2;

			other.SetMovement(v1);
			SetMovement(v2);
		}
	}*/
	return false;
}







