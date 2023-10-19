#ifndef BLACKJACK_HPP_INCLUDED
#define BLACKJACK_HPP_INCLUDED

#include "Deck.hpp"
#include "Hand.hpp"

#include <iostream>
#include <chrono>
#include <thread>

int blackjackGameStart();
int handTotal(Hand handToTotal);
void printHand(Hand handToPrint);

#endif // BLACKJACK_HPP_INCLUDED
