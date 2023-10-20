#ifndef BLACKJACK_HPP_INCLUDED
#define BLACKJACK_HPP_INCLUDED

#include "Deck.hpp"
#include "Hand.hpp"

#include <iostream>
#include <thread>
#include <chrono>

int blackjackGameStart();
int handTotal(Hand handToTotal);
void printHand(Hand handToPrint);
void playerTurn(Hand handToPlay, bool didDoubleDown);
bool checkDoubleDown();
bool checkBlackjack(Hand handToCheck);

#endif // BLACKJACK_HPP_INCLUDED
