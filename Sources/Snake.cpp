#include "Definitions.h"
#include "Snake.h"

#include <iostream>

snakePart::snakePart(int _xPos, int _yPos) : xPos(_xPos), yPos(_yPos)
{
}

Snake::Snake()
{
}

Snake::Snake(GameDataRef& _data) : data(_data)
{
	//set snake dir to null
	dir = -1;
	
	snakeBody.push_back(snakePart(START_BLACK_BLOCK + 3, HEIGHTEST_PLAYABLE_BLOCK + 1));
	
	//get the size of the snake for calcul of the score
	startSize = snakeBody.size();
}

Snake::~Snake()
{
}

sf::Sprite & Snake::getHeadSprite()
{
	return snakeBody[0].snakePartSprite;
}

int Snake::getStartSize()
{
	return startSize;
}

std::vector<snakePart>& Snake::getSnakeBody()
{
	return snakeBody;
}

bool Snake::checkCollide()
{
	if (snakeBody.size() > 2)
	{
		for (size_t i = 1; i < snakeBody.size(); i++)
		{
			if (snakeBody[0].xPos == snakeBody[i].xPos && snakeBody[0].yPos == snakeBody[i].yPos)
				return true;
		}
	}
	
	if (snakeBody[0].xPos < START_BLACK_BLOCK || snakeBody[0].yPos < HEIGHTEST_PLAYABLE_BLOCK || snakeBody[0].xPos >= END_BLACK_BLOCK || snakeBody[0].yPos * BLOCK_SIZE >= this->data->window.getSize().y - 1)
		return true;

	return false;
}

void Snake::grow()
{
	//spawn new part of snake out of the screen
	snakeBody.push_back(snakePart(-5, -5));
}

void Snake::updateDirection(int _dir)
{
	dir = _dir;
}

void Snake::updatePosition()
{
	if (dir != -1)
	{
		if (clock.getElapsedTime().asMilliseconds() > MOVEMENT_SPEED)
		{
			for (int i = snakeBody.size() - 1; i > 0; i--)
			{
				snakeBody[i].xPos = snakeBody[i-1].xPos;
				snakeBody[i].yPos = snakeBody[i-1].yPos;
			}
			switch (dir)
			{
			case 0:
				snakeBody[0].yPos -= 1;
				break;
			case 1:
				snakeBody[0].yPos += 1;
				break;
			case 2:
				snakeBody[0].xPos -= 1;
				break;
			case 3:
				snakeBody[0].xPos += 1;
				break;
			default:
				break;
			}

			clock.restart();
		}
	}
}

void Snake::draw()
{	
		for (size_t i = 0; i < snakeBody.size(); i++)
		{
			if (i == 0)
				snakeBody[i].snakePartSprite.setTexture(data->assetManager.getTexture("whiteBlock"));
			else
				snakeBody[i].snakePartSprite.setTexture(data->assetManager.getTexture("greenBlock"));
		
			snakeBody[i].snakePartSprite.setPosition(snakeBody[i].xPos * (float)BLOCK_SIZE - 1, snakeBody[i].yPos * (float)BLOCK_SIZE - 1);
		
			data->window.draw(snakeBody[i].snakePartSprite);
		}
}
