#ifndef DECK_HPP_INCLUDED
#define DECK_HPP_INCLUDED

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include "Card.hpp"

class Deck{

    public:
        void createDeck();
        void shuffleDeck();
        void printDeck();
        Card dealCard();

    private:
        std::vector<Card> mainDeck;
};
#endif // DECK_HPP_INCLUDED
