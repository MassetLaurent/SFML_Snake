#ifndef GAME
#define GAME

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"


struct GameData
{
	sf::RenderWindow window;
	AssetManager assetManager;
	InputManager inputManager;
	StateMachine stateMachine;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
private:
	GameDataRef data = std::make_shared<GameData>();
	sf::Clock dtClock;
	const float dt = 1.f / 60.f;

	void run();

public:
	Game();
	virtual ~Game();

	void handleInput();


	void update();
	void render();
};
#endif // !GAME
