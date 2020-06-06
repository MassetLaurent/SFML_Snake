#include <sstream>

#include "Definitions.h"
#include "PlayState.h"
#include "GameOverState.h"

#include <iostream>


PlayState::PlayState(GameDataRef _data) : data(_data)
{
	init();
}

PlayState::~PlayState()
{
}

void PlayState::init()
{
	srand(time(NULL));

	//loading textures
	this->data->assetManager.loadTexture("blackBlock", BLACK_BLOCK_FILEPATH);
	this->data->assetManager.loadTexture("redBlock", RED_BLOCK_FILEPATH);
	this->data->assetManager.loadTexture("greenBlock", GREEN_BLOCK_FILEPATH);
	this->data->assetManager.loadTexture("whiteBlock", WHITE_BLOCK_FILEPATH);
	this->data->assetManager.loadTexture("background", BACKGROUND_FILEPATH);
	
	//set Sprites
	blackBlockSprite.setTexture(this->data->assetManager.getTexture("blackBlock"));
	redBlockSprite.setTexture(this->data->assetManager.getTexture("redBlock"));
	greenBlockSprite.setTexture(this->data->assetManager.getTexture("greenBlock"));
	backgroundSprite.setTexture(this->data->assetManager.getTexture("background"));

	//init snake, apple and variables
	apple = Apple(data);
	snake = Snake(data);
	gameOver = false;

	//init GUI text
	scoreText.setString("Score : 0");
	scoreText.setPosition(
		(this->data->window.getSize().x / 2) - scoreText.getGlobalBounds().width / 2, 
		10.f);
	scoreFont = this->data->assetManager.getFont("pixel");
	scoreText.setCharacterSize(50);
	scoreText.setFont(scoreFont);
	scoreText.setFillColor(sf::Color(255,50,0));
	
}

bool PlayState::isCollide(sf::Sprite _spriteA, sf::Sprite _spriteB)
{
	if (_spriteA.getGlobalBounds().intersects(_spriteB.getGlobalBounds()))
	{
		return true;
	}
	return false;
}

void PlayState::updateScore()
{
	std::stringstream ss;

	ss.str("");

	ss << "Score : " << snake.getSnakeBody().size() - snake.getStartSize();

	scoreText.setString(ss.str());
}

void PlayState::handleInput()
{
	sf::Event sfmlEvents;

	while (this->data->window.pollEvent(sfmlEvents))
	{
		if (sfmlEvents.type == sf::Event::Closed)
			this->data->window.close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			this->data->window.close();


		//update direction for the snake
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			snake.updateDirection(0);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			snake.updateDirection(1);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			snake.updateDirection(2);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			snake.updateDirection(3);
	}
}

void PlayState::update(const float &_dt)
{
	snake.updatePosition();

	gameOver = snake.checkCollide();
	
	if (gameOver)
		data->stateMachine.addState(StateRef(new GameOverState(data, snake.getSnakeBody().size() - snake.getStartSize())), true);

	if (isCollide(snake.getHeadSprite(), apple.getSprite()))
	{
		while (apple.checkCollideAppleAndSnake(snake.getSnakeBody()))
			apple.spawnNewApple();

		snake.grow();
	}

	updateScore();
}

void PlayState::render(const float &_dt)
{
	this->data->window.clear(sf::Color(0,100,40));

	this->data->window.draw(backgroundSprite);

	//draw background blocks
	for (size_t i = START_BLACK_BLOCK; i < END_BLACK_BLOCK; i++)
	{
		for (size_t j = HEIGHTEST_PLAYABLE_BLOCK; j < ROW; j++)
		{
			blackBlockSprite.setPosition(i * (float)BLOCK_SIZE, j * (float)BLOCK_SIZE);
			this->data->window.draw(blackBlockSprite);
		}
	}

	//draw snake
	snake.draw();

	//draw apple
	apple.draw();

	//score
	this->data->window.draw(scoreText);

	this->data->window.display();
}
