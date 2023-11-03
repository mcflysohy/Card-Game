#ifndef WAR_HPP_INCLUDED
#define WAR_HPP_INCLUDED

#include "Deck.hpp"
#include "Hand.hpp"
#include "TextureManager.hpp"
#include "GameState.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class WarGame : public GameState
{	
	public:
		virtual void init();
		
		virtual void handleEvents();
		virtual void update();
		virtual void draw(float dt);
		
		virtual void pause();
		virtual void resume();

	private:
		int width = 800;
		int height = 600;
		
		Deck gameDeck;
		
		Hand playerHand;
		Hand opponentHand;
		Hand gameHand;

		TextureManager texManager;
		sf::RenderWindow window;

		bool isAtWar = false;

		sf::Clock clock;

		std::string workingDirectory = "../cardTextures/basicfront/";
		std::string cardBackLocation = "../cardTextures/basicfront/redback1.png";

		void dealStartingHands();
		void loadTextures();
		void atWar();
		void moveCardsToGameHand();
};
#endif // WAR_HPP_INCLUDED