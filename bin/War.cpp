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
				if (!playerPlayedCard)
				{
					playerPlayedCard = true;
					
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

	// draw player face down hand
	playerHand.drawCardFromHand(window, 30, 200, 1);
	// draw opponent face down hand
	opponentHand.drawCardFromHand(window, 650, 200, 1);

	if (!(gameHand.mainHand.empty()))
	{	
		for (auto i = 0; i <= (gameHand.mainHand.size()); i++)
		{
			gameHand.drawCardFromHand(window, 160, (200 + (30*(i/2))), i);
			gameHand.drawCardFromHand(window, 500, (200 + (30*(i/2))), i+1);
			
			i++;
		}
	}

	// end the current frame
	window.display();
}

void WarGame::update()
{
	sf::Time elapsed = clock.getElapsedTime();
	
	if (elapsed.asSeconds() > 1)
	{
		if (playerPlayedCard)
		{			
			if (playerHand.getCardValue(0) > opponentHand.getCardValue(0))
			{
				moveCardsToGameHand();
				
				isAtWar = false;
				
			}
			else if (playerHand.getCardValue(0) < opponentHand.getCardValue(0))
			{
				moveCardsToGameHand();
				
				isAtWar = false;
			}
			if (playerHand.getCardValue(0) == opponentHand.getCardValue(0))
			{
				moveCardsToGameHand();
				
				isAtWar = true;
				
				atWar();
			}
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

void WarGame::atWar()
{
	for (auto i = 0; i < 2; i++)
	{
		gameHand.addCardToHand(playerHand.getCardFromPosition(0));
		gameHand.addCardToHand(opponentHand.getCardFromPosition(0));
		playerHand.removeCard(0);
		opponentHand.removeCard(0);
	}
}

void WarGame::moveCardsToGameHand()
{
	gameHand.addCardToHand(playerHand.getCardFromPosition(0));
	gameHand.addCardToHand(playerHand.getCardFromPosition(0));
	playerHand.removeCard(0);
	opponentHand.removeCard(0);
}

void WarGame::transferGameHandToWinner(bool playerWon)
{
	/*if (playerWon)
	{
		for (auto i = playerHand
	}*/
}