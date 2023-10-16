#ifndef BLACKJACK_HPP_INCLUDED
#define BLACKJACK_HPP_INCLUDED

#include "Deck.hpp"
#include "Hand.hpp"

#include <iostream>

int blackjackGameStart();
int handTotal(Hand handToTotal);
void printHand(Hand handToPrint);

#endif // BLACKJACK_HPP_INCLUDED
