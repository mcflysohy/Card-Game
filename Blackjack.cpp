#include "Blackjack.hpp"

int blackjackGameStart()
{

// create and shuffle gameDeck
Deck gameDeck;
gameDeck.createDeck();
gameDeck.shuffleDeck();

// create vectors of Cards to hold the hands
Hand playerHand;
Hand dealerHand;

// deal the starting hands
playerHand.addCardToHand(gameDeck.dealCard());
dealerHand.addCardToHand(gameDeck.dealCard());
playerHand.addCardToHand(gameDeck.dealCard());
dealerHand.addCardToHand(gameDeck.dealCard());

// show the hands
std::cout << "Your hand is:\n";
printHand(playerHand);

std::cout << "\n";

std::cout << "The dealer is showing: \n";
dealerHand.printCard(1);


// player's turn
bool playerHitting = true;
bool playerBusted = false;

while(playerHitting)
{
    std::cout << "\nWould you like to (H)it or (S)tay?\n";

    std::string playerChoice;
    std::cin >> playerChoice;

    if (playerChoice == "h" || playerChoice == "H")
    {
        std::cout << "\n";
        playerHand.addCardToHand(gameDeck.dealCard());
        std::cout << "Your hand is:\n";
        printHand(playerHand);
        std::cout<< "\nTotaling: " << handTotal(playerHand) << "\n";
        if (handTotal(playerHand) > 21)
        {
            std::cout << "You busted.  Better luck next time ...";
            playerHitting = false;
            playerBusted = true;
        }
    }
    else if (playerChoice == "s" || playerChoice == "S")
    {
        std::cout << "Your total is " << handTotal(playerHand) << "\n";
        if (handTotal(playerHand) > 21)
            std::cout << "You busted.  Better luck next time ...";
        playerHitting = false;
        playerBusted = true;
    }
    else
        std::cout << "Invalid Input Please Try Again, (H)it or (S)tay\n";
}
// dealer's turn if player didn't bust
if (playerBusted = false)
{
    std::cout << "The dealer has:\n";
    printHand(dealerHand);
    std::cout << "\n";

    while (handTotal(dealerHand) < 17)
    {
        std::cout << "The dealer hits\n\n";
        dealerHand.addCardToHand(gameDeck.dealCard());
        std::cout << "The dealer's hand is now:\n";
        printHand(dealerHand);
        std::cout << "Totalling: " << handTotal(dealerHand) << "\n\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    }

    if (handTotal(dealerHand) > 21)
        std::cout << "The dealer busted.  You win!!!!!";
    else
    {
    std::cout << "The dealer stands with: " << handTotal(dealerHand) << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

        if (handTotal(dealerHand) > handTotal(playerHand))
        std::cout << "The dealer wins.  Better luck next time :p";
    else if (handTotal(playerHand) > handTotal(dealerHand))
        std::cout << "You win.  Congratulations!!!!!";
    else
        std::cout << "It's a push.  At least you didn't lose money";
    }
}

return (0);

} // end of game

int handTotal(Hand handToTotal)
{
    int runningCount = 0;
    int numberOfAces = 0;

    for (int i = 0; i < handToTotal.totalNumberOfCards; i++)
    {
        int trueValue = 0;

        if (handToTotal.cardValue(i) == 11 || handToTotal.cardValue(i) == 12 || handToTotal.cardValue(i) == 13)
            trueValue = 10;

        else if (handToTotal.cardValue(i) == 1)
        {
            trueValue = 11;
            numberOfAces += 1;
        }

        else
            trueValue = handToTotal.cardValue(i);

        runningCount += trueValue;
    }

    while (numberOfAces > 0 && runningCount > 21)
    {
        runningCount -= 10;
        numberOfAces -= 1;
    }

    return runningCount;
}

void printHand(Hand handToPrint)
{
    for (int i = 0; i < handToPrint.totalNumberOfCards; i++)
    {
        handToPrint.printCard(i);
    }
}
