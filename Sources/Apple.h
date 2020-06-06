#ifndef APPLE
#define APPLE

#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Snake.h"

class Apple
{
private:
	sf::Texture appleTexture;
	sf::Sprite appleSprite; 
	GameDataRef data;

	int xPos, yPos;

public:
	Apple();
	Apple(GameDataRef& _data);
	~Apple();
	
	sf::Sprite& getSprite();

	bool checkCollideAppleAndSnake(std::vector<snakePart>_snake);
	void spawnNewApple();
	void draw();
};

#endif // !APPLE
