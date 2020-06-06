#include <sstream>
#include <fstream>

#include "GameOverState.h"

GameOverState::GameOverState(GameDataRef _data, int _score) : data(_data), score(_score)
{

}

GameOverState::~GameOverState()
{
}

void GameOverState::init()
{
	//bestscore.txt stream
	std::fstream file("Resources/bestScores.txt");
	std::string line;

	if (file.is_open())
	{
		//get the best score from the file
		getline(file,line);

		try
		{
			//try to convert data from file in an integer value
			bestScore = std::stoi(line, nullptr , 10);
		}
		catch (const std::exception&)
		{

		}

		//write our score if he's better than older best.
		if (bestScore < score)
		{
			//open again the file in write mode & erase it
			std::ofstream file("Resources/bestScores.txt");
			file << score;
			bestScore = score;
		}
		std::cout << bestScore;
	}file.close();

	//background
	data->assetManager.loadTexture("gameOverBackground","Resources/images/game_over.png");
	background.setTexture(data->assetManager.getTexture("gameOverBackground"));

	//score
	scoreFont = this->data->assetManager.getFont("pixel");

	//game score
	std::stringstream ss;
	ss << "Score : " << score;
	scoreText.setString(ss.str());
	scoreText.setPosition(
		(data->window.getSize().x / 2) - 120,
		data->window.getSize().y / 3);
	scoreText.setCharacterSize(80);
	scoreText.setFont(scoreFont);
	scoreText.setFillColor(sf::Color(255, 50, 0));

	//best score from file
	ss.str(" ");

	ss << "Best score : " << bestScore;
	BestScoreText.setString(ss.str());
	BestScoreText.setPosition(
		(data->window.getSize().x / 2) - 170,
		data->window.getSize().y / 2);
	BestScoreText.setCharacterSize(80);
	BestScoreText.setFont(scoreFont);
	BestScoreText.setFillColor(sf::Color(255, 50, 0));

}

void GameOverState::handleInput()
{
	sf::Event sfmlEvents;

	while (this->data->window.pollEvent(sfmlEvents))
	{
		if (sfmlEvents.type == sf::Event::Closed)
			this->data->window.close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			this->data->window.close();
	}
}

void GameOverState::update(const float & _dt)
{
}

void GameOverState::render(const float & _dt)
{
	data->window.clear();

	data->window.draw(background);
	data->window.draw(scoreText);
	data->window.draw(BestScoreText);

	data->window.display();
}
