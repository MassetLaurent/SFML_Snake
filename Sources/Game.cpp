#include "Definitions.h"
#include "Game.h"
#include "MainMenuState.h"

//constructor
Game::Game()
{
	this->data->window.create(sf::VideoMode(WIDTH,HEIGHT), "SFML Snake", sf::Style::Titlebar);

	data->stateMachine.addState(StateRef(new MainMenuState(data)), true);

	run();
}

Game::~Game()
{

}

//methode
void Game::run()
{
	float newTime, frameTime, interpolation;

	float currentTime = this->dtClock.getElapsedTime().asSeconds();

	float accumulator = 0.0f;

	while (this->data->window.isOpen())
	{
		this->data->stateMachine.processStatesChanges();

		newTime = this->dtClock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		if (frameTime > 0.25f)
			frameTime = 0.25f;

		currentTime = newTime;

		accumulator += frameTime;

		while (accumulator >= dt)
		{
			this->data->stateMachine.getActiveState()->handleInput();
			this->data->stateMachine.getActiveState()->update(dt);

			accumulator -= dt;
		}

		interpolation = accumulator / dt;
		this->data->stateMachine.getActiveState()->render(interpolation);
	}
}

void Game::handleInput()
{
	sf::Event sfmlEvents;
	while (this->data->window.pollEvent(sfmlEvents))
	{
		if (sfmlEvents.type == sf::Event::Closed)
			this->data->window.close();

		if (sfmlEvents.type == sf::Event::KeyPressed && sfmlEvents.key.code == sf::Keyboard::Escape)
				this->data->window.close();
	}
}

void Game::update()
{
	this->handleInput();
}

void Game::render()
{
	this->data->window.clear(sf::Color(255, 255, 255, 255));

	this->data->window.display();
}
