#pragma once
//#ifndef HANDLER_H
#define HANDLER_H
#include "GameObject.h"

class Handler
{
    GameObject *tempObject;

public:
    std::vector<GameObject*> bullets;
    std::vector<GameObject*> asteroids;
    GameObject* player;

    Handler();
    void Update();
    void Draw(sf::RenderWindow& windowRef);
    GameObject AddBullet(GameObject* tempBullet);
    GameObject AddAsteroid(GameObject* tempAsteroid);
    void RemoveDestroyable();
    GameObject FindPlayer();

};

//#endif

