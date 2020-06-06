#ifndef MAINMENUSTATE
#define MAINMENUSTATE

#include "Game.h"
#include "State.h"

class MainMenuState : public State
{
private:
	GameDataRef data;

	sf::Texture background;
	sf::Sprite backgroundSprite;

	sf::Font font;
	sf::Text startText;

	sf::Music music;

public:
	MainMenuState(GameDataRef _data);
	virtual ~MainMenuState();

	void init();

	void handleInput();
	void update(const float &dt);
	void render(const float &dt);
};

#endif // !MAINMENUSTATE
