#ifndef INPUTMANAGER
#define INPUTMANAGER

#include <SFML/Graphics.hpp>


class InputManager
{
private:

public:
	InputManager();
	virtual ~InputManager();

	bool isSpriteClicked(sf::Sprite _sprite, sf::Mouse::Button _button, sf::RenderWindow &_window);
	sf::Vector2i getMousePosition(sf::RenderWindow &_window);
};
#endif // !INPUTMANAGER
