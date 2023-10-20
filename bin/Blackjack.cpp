#include "Blackjack.hpp"

// create and shuffle gameDeck
Deck gameDeck;

// create vectors of Cards to hold the hands
Hand playerHand;
Hand dealerHand;

// other variables
bool playerBusted = false;

int blackjackGameStart()
{
gameDeck.createDeck();
gameDeck.shuffleDeck();

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

// check for blackjack
bool playerHasBlackjack = false;
bool dealerHasBlackjack = false;

playerHasBlackjack = checkBlackjack(playerHand);
dealerHasBlackjack = checkBlackjack(dealerHand);

if (dealerHasBlackjack == true && playerHasBlackjack == true)
{
    std::cout << "You have Blackjack but the dealer has:\n";
    printHand(dealerHand);
    std::cout << "\nYou both have Blackjack.  Bets are pushed.\n";
}

else if (dealerHasBlackjack == true)
{
    std::cout << "\nThe dealer has Blackjack ... Bad beat\n";
    printHand(dealerHand);
}

else if (playerHasBlackjack == true)
{
    std::cout << "\nBlackjack you win!!!!!\n";
}

else
{
    //check for double down
    bool doubleDown = false;
    doubleDown = checkDoubleDown();

    // player's turn
    playerTurn(playerHand, doubleDown);

    // dealer's turn if player didn't bust
    if (playerBusted == false)
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
            std::cout << "Totaling: " << handTotal(dealerHand) << "\n\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(4000));
        }

        if (handTotal(dealerHand) > 21)
            std::cout << "The dealer busted.  You win!!!!!";
        else
        {
        std::cout << "The dealer stands with: " << handTotal(dealerHand) << "\n\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));

        if (handTotal(dealerHand) > handTotal(playerHand))
            std::cout << "The dealer wins.  Better luck next time :p";
        else if (handTotal(playerHand) > handTotal(dealerHand))
            std::cout << "You win.  Congratulations!!!!!";
        else
            std::cout << "It's a push.  At least you didn't lose money";
        }
    } // end of dealers turn
}

return (0);

} // end of blackjackGameStart

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
} // end of handTotal(Hand handToTotal)

void printHand(Hand handToPrint)
{
    for (int i = 0; i < handToPrint.totalNumberOfCards; i++)
    {
        handToPrint.printCard(i);
    }
} // end of printHand(Hand handToPrint)

void playerTurn(Hand handToPlay, bool didDoubleDown)
{
    // player's turn
    bool playerHitting = true;

    if (didDoubleDown == true)
    {
        playerHand.addCardToHand(gameDeck.dealCard());
        std::cout << "\nYour hand is:\n";
        printHand(playerHand);
        std::cout << "\nTotaling: " << handTotal(playerHand) << "\n";
        playerHitting = false;
        if (handTotal(playerHand) > 21)
        {
            std::cout << "You busted on a double down.  Tough break.";
            playerBusted = true;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    }

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
            {
                std::cout << "You busted.  Better luck next time ...";
                playerBusted = true;
            }
            playerHitting = false;
        }
        else
            std::cout << "Invalid Input Please Try Again, (H)it or (S)tay\n";
    }
} // end of playerTurn(Hand handToPlay)

bool checkDoubleDown()
{
    bool checking = true;
    bool returnDoubleDown;
    std::string doubleDownChoice;

    while (checking)
    {
        std::cout << "Do you want to double down? (Y)es / (N)o\n";
        std::cin >> doubleDownChoice;
        if (doubleDownChoice == "Y" || doubleDownChoice == "y")
        {
            returnDoubleDown = true;
            checking = false;
        }
        else if (doubleDownChoice == "N" || doubleDownChoice == "n")
        {
            returnDoubleDown = false;
            checking = false;
        }
        else
        {
            std::cout << "Invalid input ... Please try again";
        }
    }

    return returnDoubleDown;

} // end of checkDoubleDown()

bool checkBlackjack(Hand handToCheck)
{
    bool hasBlackjack = false;

    if (handTotal(handToCheck) == 21)
        hasBlackjack = true;

    return hasBlackjack;

} // end of checkBlackjack()
