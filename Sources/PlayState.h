#ifndef PLAYSTATE
#define PLAYSTATE

#include "Game.h"
#include "State.h"

#include "Snake.h"
#include "Apple.h"

class PlayState : public State
{
private:
	GameDataRef data;
	Snake snake;
	Apple apple;

	sf::Sprite blackBlockSprite, greenBlockSprite, redBlockSprite, backgroundSprite;
	sf::Text scoreText;
	sf::Font scoreFont;

	bool gameOver;

	bool isCollide(sf::Sprite _spriteA, sf::Sprite _spriteB);
	void updateScore();
	
public:
	PlayState(GameDataRef _data);
	virtual ~PlayState();

	void init();

	void handleInput();
	void update(const float &_dt);
	void render(const float &_dt);

};
#endif // !PLAYSTATE
