#include "Hand.hpp"

void Hand::addCardToHand(Card cardToAdd)
{
    mainHand.push_back(cardToAdd);
    totalNumberOfCards += 1;
}

void Hand::printCard(int cardPosition)
{
    std::cout << mainHand[cardPosition].getPipString() << " of " << mainHand[cardPosition].getSuitString() << "\n";
}

int Hand::cardValue(int cardPosition)
{
    return mainHand[cardPosition].getCardValue();
}

void Hand::removeCard(int cardPosition)
{
	mainHand.erase(mainHand.begin()+cardPosition);
	totalNumberOfCards -= 1;
}

int Hand::getCardValue(int cardPosition)
{
	return mainHand[cardPosition].getCardValue();
}

void Hand::drawCardFromHand(sf::RenderWindow &window, float xPos, float yPos, int cardPosition)
{
	mainHand[cardPosition].drawCard(window, xPos, yPos);
}

Card Hand::getCardFromPosition(int cardPosition)
{
	return mainHand[cardPosition];
}