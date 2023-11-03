#ifndef HAND_HPP_INCLUDED
#define HAND_HPP_INCLUDED

#include "Card.hpp"
#include <vector>
#include <iostream>

class Hand{

    public:
        void addCardToHand(Card cardToAdd);
        void printCard(int cardPosition);
        int cardValue(int cardPosition);
        int totalNumberOfCards = 0;
        void removeCard(int cardPosition);
		int getCardValue(int cardPosition);
		void drawCardFromHand(sf::RenderWindow &window, float xPos, float yPos, int cardPosition);
		Card getCardFromPosition(int cardPosition);
		
        std::vector<Card> mainHand;

};

#endif // HAND_HPP_INCLUDED
