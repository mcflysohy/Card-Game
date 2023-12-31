#ifndef CARD_HPP_INCLUDED
#define CARD_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <string>

enum Pip
        {
            NoPip=0,
            Ace=1,
            Two,
            Three,
            Four,
            Five,
            Six,
            Seven,
            Eight,
            Nine,
            Ten,
            Jack,
            Queen,
            King
        };
enum Suit
        {
            NoSuit=0,
            Hearts=1,
            Diamonds,
            Clubs,
            Spades
        };

class Card{

    public:
        Card(Suit suit, Pip pip);
        Card();

        sf::Sprite cardSprite;
        sf::Sprite backSprite;
        std::string intCardName; // holds the two integer value for card to help load textures
        std::string cardBack; // holds location of cardBack
		
		bool cardFaceUp = false;

        std::string getSuitString();
        std::string getPipString();
        
        int getCardValue();
        std::string getCardName();

        void drawCard(sf::RenderWindow &window, float xPos, float yPos);
	
	private:	
        Suit cardSuit;
        Pip cardPip;
};

#endif // CARD_HPP_INCLUDED
