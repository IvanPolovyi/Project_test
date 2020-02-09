#pragma once
#define GAME_H
#include "Handler.h"
#include "Player.h"


extern  int SCREEN_WIDTH;
extern  int SCREEN_HEIGHT;

class Game
{
public:

	sf::Texture texture;
	sf::Sprite background;
	float timeBetweenShots;
	Handler handler;
	sf::RenderWindow& window;
	bool isRunning;
	Game(sf::RenderWindow& windowRef);
	void Init();
	void Start();
	void Run();

	static void SetScreenWidth(int sw);
	static void SetScreenHeight(int sh);
	
};
