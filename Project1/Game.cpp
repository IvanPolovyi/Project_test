#include "SFML/Graphics.hpp"
#include <iostream>
#include <math.h>
#include <vector>
#include "Game.h"
#include "Handler.h"
#include "Player.h"
#include "SmallAsteroid.h"
#include "BigAsteroid.h"
#include "Bullet.h"
#include  "time.h"
#include <thread>


using namespace std;
using namespace sf;

 int SCREEN_WIDTH = 800;
 int SCREEN_HEIGHT = 600;

static int GetScreenWidth()
{
	return SCREEN_WIDTH;
};
static int GetScreenHeight()
{
	return SCREEN_HEIGHT;

};

Game::Game(sf::RenderWindow& windowRef): window(windowRef)
{
	isRunning = false;
};
void Game::Init()
{
	if (!texture.loadFromFile("res/background.png"))
	{
		std::cout << "Load failed" << std::endl;
		system("pause");
	}
	texture.setRepeated(true);
	background.setTexture(texture);
	
	Player player(Vector2f(100, 100), &handler, ID::Player, handler.bullets.size(), window);
	handler.player = &player;

	handler.AddAsteroid(new BigAsteroid(Vector2f(100, SCREEN_HEIGHT/2),
		&handler, Vector2f(2,0), ID::SmallAsteroid, handler.bullets.size()));
	
	handler.AddAsteroid(new BigAsteroid(Vector2f(SCREEN_WIDTH-100, SCREEN_HEIGHT / 2),
		&handler, Vector2f(-1, 0), ID::SmallAsteroid, handler.bullets.size()));
	
	/*for (int i = 0; i < 5; i++) {
		handler.AddAsteroid(new SmallAsteroid (Vector2f(i*100, i*100),
			handler, Vector2f(i / 2, i / 2),ID::SmallAsteroid, handler.bullets.size()));
	}
	
	
	for (int i = 0; i < 5; i++) {

		handler.AddAsteroid(new BigAsteroid(Vector2f(SCREEN_WIDTH - i * 100, SCREEN_HEIGHT - i* 100),
			handler,  Vector2f(i / -2, i / -2), ID::BigAsteroid, handler.bullets.size()));
	}*/

	Start();
}
void Game::Start()
{
	isRunning = true;
	cout << handler.bullets.size() << endl;
	
	Run();
	
}
void Game::Run()
{
	int frameCounter=10;
	
	while (window.isOpen()) {
		Event event{};
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		handler.Update();
		
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if(frameCounter<10)
			{
				frameCounter++;
			}
			else {
				frameCounter = 0;
				GameObject tempPlayer = handler.FindPlayer();
				Vector2f aimDir;
				Vector2f mousePosWindow = Vector2f(Mouse::getPosition(window));
				aimDir = mousePosWindow - tempPlayer.GetCenter();
				Vector2f aimDirNorm = aimDir / sqrt(aimDir.x * aimDir.x + aimDir.y * aimDir.y);

				GameObject b = handler.AddBullet(new Bullet(tempPlayer.position + Vector2f(20.0, 20.0),
					&handler, aimDirNorm * 10.0f, ID::Bullet, handler.bullets.size()));
			}
		}
		
		handler.RemoveDestroyable();
			
			
		//cout << handler.bullets.size() << endl;

		window.clear();
		background.setTextureRect(sf::IntRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
		window.draw(background);
		handler.Draw(window);
		//background.setScale(,)

		window.display();
		

	}
}





int main() {

	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Asteroid");
	window.setFramerateLimit(60);
	Game game(window);
	game.Init();
	return 0;
};


