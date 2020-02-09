#include "SFML/Graphics.hpp"
#include <iostream>
#include <ostream> 
#include <math.h>
#include <vector>
#include <list>

#include "Handler.h"

using namespace std;
using namespace sf;

Handler::Handler()
{

} ;

void Handler::Update() {

	for (auto& i : bullets)
	{	
		tempObject = i;
		tempObject->Update();
	};
	for (auto& i : asteroids)
	{
		tempObject = i;
		tempObject->Update();
	};
	player->Update();	
}
void Handler::Draw(sf::RenderWindow& windowRef) {

	for (auto& i : bullets)
	{
		tempObject = i;
		tempObject->Draw(windowRef);
	};
	for (auto& i : asteroids)
	{
		tempObject = i;
		tempObject->Draw(windowRef);
	};
	player->Draw(windowRef);
};

GameObject Handler::AddBullet(GameObject* tempBullet) {
	
	bullets.push_back(tempBullet);
	return *tempBullet;
}
GameObject Handler::AddAsteroid(GameObject* tempAsteroid)
{
	asteroids.push_back(tempAsteroid);
	return *tempAsteroid;
}
;
void Handler::RemoveDestroyable() {
	
	for (int i=0; i < bullets.size(); i++)
	{
		if (bullets[i]->GetID() == ID::Destroyable)
		{
			bullets.erase(bullets.begin() + bullets[i]->getIdNumber());
			
			for(int j = i;j < bullets.size();j++)
			{
				bullets[i]->setIdNumber(bullets[i]->getIdNumber() - 1);
			}
		}
	}
	
};

GameObject Handler::FindPlayer()
{
	return *player;
}

