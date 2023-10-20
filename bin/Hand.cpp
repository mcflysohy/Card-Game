#include "Hand.hpp"

void Hand::addCardToHand(Card cardToAdd)
{
    mainHand.push_back(cardToAdd);
    totalNumberOfCards = totalNumberOfCards + 1;
}

void Hand::printCard(int cardPosition)
{
    std::cout << mainHand[cardPosition].getPipString() << " of " << mainHand[cardPosition].getSuitString() << "\n";
}

int Hand::cardValue(int cardPosition)
{
    return mainHand[cardPosition].getCardValue();
}
