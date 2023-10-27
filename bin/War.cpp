#include "War.hpp"

TextureManager texMgr;
std::string workingDirectory = "/home/mcflysohy/Documents/gitprojects/Card-Game/cardTextures/basicfront/";
Deck gameDeck;
Hand playerHand;
Hand opponentHand;

int warGameStart()
{
	sf::RenderWindow window(sf::VideoMode(800,600),"War");

	gameDeck.createDeck();
	gameDeck.shuffleDeck();

	loadTextures();

	dealStartingHands();



	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window event's 
		sf::Event event;
		while (window.pollEvent(event))
		{
			// close requested event; close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// clear the window with black
		window.clear(sf::Color::Black);

		// draw everything here
		window.draw(playerHand.mainHand[1].drawCard());

		// end the current frame
		window.display();
	}

	return 0;
} // end of warGameStart()

void dealStartingHands()
{
	for (auto i = 1; i<27; i++)
	{
		playerHand.addCardToHand(gameDeck.dealCard());
		opponentHand.addCardToHand(gameDeck.dealCard());
	}
}

void loadTextures()
{
	for (auto i = 1; i <= 4; i++)
	{
		for (auto j = 1; j <= 13; j++)
		{
			std::string tempString = std::to_string(i) + std::to_string(j);
			std::string tempFileName = workingDirectory + tempString + ".jpg";
			texMgr.loadTexture(tempString, tempFileName);
		}
	}

	for (auto s = 0; s <= 51; s++)
	{
		gameDeck.mainDeck[s].cardSprite.setTexture(texMgr.getRef(gameDeck.mainDeck[s].intCardName));
	}
}