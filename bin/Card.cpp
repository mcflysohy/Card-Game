#include "Card.hpp"
#include <iostream>
#include <string>

Card::Card(Suit suit, Pip pip)
{
    cardSuit = suit;
    cardPip = pip;
    intCardName = std::to_string(suit) + std::to_string(pip);
}

Card::Card()
{
    cardSuit = (Suit)0;
    cardPip = (Pip)0;

}

std::string Card::getSuitString()
{
    std::string tempSuit;

    switch (cardSuit) {
        case 0:
            return "Blank";
        case 1:
            return "Hearts";
        case 2:
            return "Diamonds";
        case 3:
            return "Clubs";
        case 4:
            return "Spades";
        default:
            return "Blank";
    }
}

std::string Card::getPipString()
{
    std::string tempPip;

    switch (cardPip) {
        case 0:
            return "Blank";
        case 1:
            return "Ace";
        case 2:
            return "Two";
        case 3:
            return "Three";
        case 4:
            return "Four";
        case 5:
            return "Five";
        case 6:
            return "Six";
        case 7:
            return "Seven";
        case 8:
            return "Eight";
        case 9:
            return "Nine";
        case 10:
            return "Ten";
        case 11:
            return "Jack";
        case 12:
            return "Queen";
        case 13:
            return "King";
        default:
            return "Blank";
    }
}

int Card::getCardValue()
{
    return (int)cardPip;
}

std::string Card::getCardName()
{
    return intCardName;
}

void Card::drawCard(sf::RenderWindow &window, float xPos, float yPos)
{
    if (cardFaceUp)
    {
        cardSprite.setPosition(sf::Vector2f(xPos, yPos));
        window.draw(cardSprite);
    }
    else
    {
        backSprite.setPosition(sf::Vector2f(xPos, yPos));
        window.draw(backSprite);
    }
}
