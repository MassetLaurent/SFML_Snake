#include "Definitions.h"
#include "Apple.h"

Apple::Apple()
{
}

Apple::Apple(GameDataRef& _data) : data(_data)
{	
	spawnNewApple();
	appleSprite.setTexture(data->assetManager.getTexture("redBlock"));
	appleSprite.setScale(sf::Vector2f(0.8f, 0.8f));
}

Apple::~Apple()
{
}

sf::Sprite & Apple::getSprite()
{
	return appleSprite;
}

bool Apple::checkCollideAppleAndSnake(std::vector<snakePart> _snake)
{
	for (size_t i = 0; i < _snake.size(); i++)
	{
		if (yPos == _snake[i].yPos && xPos == _snake[i].xPos)
			return true;
	}
	return false;
}

void Apple::spawnNewApple()
{
	xPos = rand() % COL;
	yPos = rand() % ROW;

	while (xPos >= END_BLACK_BLOCK || xPos <= START_BLACK_BLOCK)
		xPos = rand() % COL;

	while (yPos <= HEIGHTEST_PLAYABLE_BLOCK)
		yPos = rand() % ROW;

	appleSprite.setPosition(xPos * (float)BLOCK_SIZE, yPos * (float)BLOCK_SIZE);	
}

void Apple::draw()
{
	data->window.draw(appleSprite);
}
