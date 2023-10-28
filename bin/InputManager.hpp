#ifndef INPUT_MANAGER_HPP_INCLUDED
#define INPUT_MANAGER_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class InputManager
{
	public:
		InputManager() {}
		~InputManager() {}

		bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

		sf::Vector2i getMousePosition (sf::RenderWindow &window);

};

#endif