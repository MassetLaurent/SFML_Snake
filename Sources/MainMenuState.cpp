#include "Definitions.h"
#include "MainMenuState.h"
#include "PlayState.h"

MainMenuState::MainMenuState(GameDataRef _data) : data(_data)
{
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::init()
{
	this->data->assetManager.loadTexture("main menu background", MAIN_MENU_BAKGROUND_FILEPATH);
	backgroundSprite.setTexture(this->data->assetManager.getTexture("main menu background"));

	this->data->assetManager.loadFont("pixel", FONT_FILEPATH);
	startText.setFont(this->data->assetManager.getFont("pixel"));
	startText.setString("Start !");
	startText.setFillColor(sf::Color(255,255,255));
	startText.setCharacterSize(100);

	startText.setPosition(this->data->window.getSize().x / 2.f - 100.f, this->data->window.getSize().y / 2.f);

	//init music
	music.openFromFile("Resources/sound/Dystopia.ogg");
	music.play();
}

void MainMenuState::handleInput()
{
	sf::Event sfmlEvents;

	while (this->data->window.pollEvent(sfmlEvents))
	{
		if (sfmlEvents.type == sf::Event::Closed)
			this->data->window.close();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			this->data->window.close();

		if (startText.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(this->data->window))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			this->data->stateMachine.addState(StateRef(new PlayState(data)), false);
	}
}


void MainMenuState::update(const float & dt)
{

}

void MainMenuState::render(const float & dt)
{
	this->data->window.clear();

	this->data->window.draw(backgroundSprite);
	this->data->window.draw(startText);

	this->data->window.display();
}
