#include "Deck.hpp"

void Deck::createDeck()
{

    for (int s=1; s<=4; s++){
        for (int p=1; p<=13; p++){
            Suit tempSuit = (Suit)s;
            Pip tempPip = (Pip)p;
            Card tempCard(tempSuit, tempPip);
            mainDeck.push_back(tempCard);
        }
    }
}

void Deck::shuffleDeck()
{
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle ( this->mainDeck.begin(), this->mainDeck.end(), g);
}

void Deck::printDeck()
{

    for (int i=0; i<mainDeck.size(); i++){
        std::cout << mainDeck[i].getPipString() << " of " << mainDeck[i].getSuitString() << "\n";
    }

    return;
}

Card Deck::dealCard()
{

    Card tempCard;
    tempCard = mainDeck.back();
    mainDeck.pop_back();

    return tempCard;

}
