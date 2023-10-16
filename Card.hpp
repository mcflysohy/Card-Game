#ifndef CARD_HPP_INCLUDED
#define CARD_HPP_INCLUDED

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

        Suit cardSuit;
        Pip cardPip;

        std::string getSuitString();
        std::string getPipString();
        int getCardValue();

};

#endif // CARD_HPP_INCLUDED
