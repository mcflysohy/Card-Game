#ifndef WAR_HPP_INCLUDED
#define WAR_HPP_INCLUDED

#include "Deck.hpp"
#include "Hand.hpp"
#include "TextureManager.hpp"
#include "GameState.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class WarGame() : public GameState
{	
	void init();
	
	void handleEvents();
	void update();
	void draw();
	
	void pause();
	void resume();
	
	void dealStartingHands();
	void loadTextures();
}
#endif // WAR_HPP_INCLUDED