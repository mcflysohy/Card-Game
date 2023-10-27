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
        
        std::vector<Card> mainHand;

};

#endif // HAND_HPP_INCLUDED
