#ifndef SNAKE
#define SNAKE

#include <SFML/Graphics.hpp>
#include <vector>

#include "Game.h"

struct snakePart
{
	snakePart(int _xPos, int _yPos);
	sf::Texture snakePartTexture;
	sf::Sprite snakePartSprite;

	sf::RectangleShape tempShape;

	int xPos, yPos;
};

class Snake
{
private:
	std::vector<snakePart> snakeBody;
	sf::Clock clock; 
	GameDataRef data;

	int dir;

public:
	Snake();
	Snake(GameDataRef& _data);
	~Snake();

	sf::Sprite& getHeadSprite();
	int getStartSize();
	std::vector<snakePart>& getSnakeBody();

	bool checkCollide();
	int startSize;

	void grow();
	void updateDirection(int _dir);
	void updatePosition();
	void draw();
};

#endif // !SNAKE
