#ifndef GAMEOVER
#define GAMEOVER

#include "Game.h"
#include "State.h"

class GameOverState : public State
{
private:
	GameDataRef data;

	sf::Sprite background;
	sf::Text scoreText;
	sf::Text BestScoreText;
	sf::Font scoreFont;

	int score;
	int bestScore;

public:
	GameOverState(GameDataRef _data, int _score);
	virtual ~GameOverState();

	void init();

	void handleInput();
	void update(const float &_dt);
	void render(const float &_dt);

};
#endif // !GAMEOVER
