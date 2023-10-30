#include "War.hpp"

void WarGame::init()
{
	window.create(sf::VideoMode(width,height),"War");

	gameDeck.createDeck();
	gameDeck.shuffleDeck();

	loadTextures();

	dealStartingHands();

	draw(0);

	handleEvents();
}

void WarGame::handleEvents()
{
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
			else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
			{
				if (!playerHand.mainHand[1].cardFaceUp)
				{
					playerHand.mainHand[1].cardFaceUp = true;
					opponentHand.mainHand[1].cardFaceUp = true;
					clock.restart();
				}
			}
		}

		update();

		// draw everything here
		draw(0);
	}
}

void WarGame::draw(float dt)
{
	// clear the window with black
	window.clear(sf::Color::Black);

	// if player has clicked their card, draw the top card of both decks
	if (playerHand.mainHand[1].cardFaceUp)	
	{
		playerHand.mainHand[1].drawCard(window, 160, 200);
		opponentHand.mainHand[1].drawCard(window, 500, 200);
	}

	// draw player face down hand
	playerHand.mainHand[2].drawCard(window, 30, 200);
	// draw opponent face down hand
	opponentHand.mainHand[2].drawCard(window, 650, 200);

	// end the current frame
	window.display();
}

void WarGame::update()
{
	sf::Time elapsed = clock.getElapsedTime();
	
	if (elapsed.asSeconds() > 3)
	{
		if (playerHand.mainHand[1].cardFaceUp)
		{
			if ((playerHand.mainHand[1].getCardValue()) > (opponentHand.mainHand[1].getCardValue()))
				playerScore += 2;
			else
				opponentScore += 2;

			playerHand.mainHand.erase(playerHand.mainHand.begin());
			opponentHand.mainHand.erase(opponentHand.mainHand.begin());
		}
	}
}

void WarGame::pause()
{
	// code for when the the game is paused
}

void WarGame::resume()
{
	// code for when the game is resumed
}

void WarGame::dealStartingHands()
{
	for (auto i = 1; i<27; i++)
	{
		playerHand.addCardToHand(gameDeck.dealCard());
		opponentHand.addCardToHand(gameDeck.dealCard());
	}
}

void WarGame::loadTextures()
{
	// load card back
	texManager.loadTexture("cardback", cardBackLocation);

	for (auto i = 1; i <= 4; i++)
	{
		for (auto j = 1; j <= 13; j++)
		{
			std::string tempString = std::to_string(i) + std::to_string(j);
			std::string tempFileName = workingDirectory + tempString + ".jpg";
			texManager.loadTexture(tempString, tempFileName);
		}
	}

	for (auto s = 0; s <= 51; s++)
	{
		gameDeck.mainDeck[s].cardSprite.setTexture(texManager.getRef(gameDeck.mainDeck[s].intCardName));
		gameDeck.mainDeck[s].backSprite.setTexture(texManager.getRef("cardback"));
	}
}