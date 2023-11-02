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
				if (!playerHand.mainHand[0].cardFaceUp)
				{
					playerHand.mainHand[0].cardFaceUp = true;
					opponentHand.mainHand[0].cardFaceUp = true;
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
	if (playerHand.mainHand[0].cardFaceUp)	
	{
		playerHand.mainHand[0].drawCard(window, 160, 200);
		opponentHand.mainHand[0].drawCard(window, 500, 200);
	}

	// draw player face down hand
	playerHand.mainHand[1].drawCard(window, 30, 200);
	// draw opponent face down hand
	opponentHand.mainHand[1].drawCard(window, 650, 200);
	
	// if atWar
	if (numberOfWars > 0)
	{
		playerHand.mainHand[1].drawCard(window, 160, 230);
		opponentHand.mainHand[1].drawCard(window, 500, 230);
		playerHand.mainHand[2].drawCard(window, 160, 260);
		opponentHand.mainHand[2].drawCard(window, 500, 260);
	}

	// end the current frame
	window.display();
}

void WarGame::update()
{
	sf::Time elapsed = clock.getElapsedTime();
	
	if (elapsed.asSeconds() > 1)
	{
		if (playerHand.mainHand.empty())
		{
			std::cout << "Player Wins\n";
		}
		
		if (opponentHand.mainHand.empty())
		{
			std::cout << "Player Loses\n";
		}

		if (playerHand.mainHand[0].cardFaceUp)
		{
			if ((playerHand.mainHand[0].getCardValue()) > (opponentHand.mainHand[0].getCardValue()))
			{
				playerHand.mainHand.push_back(playerHand.mainHand[0]);
				playerHand.mainHand.push_back(opponentHand.mainHand[0]);
				playerHand.mainHand.erase(playerHand.mainHand.begin());
				opponentHand.mainHand.erase(opponentHand.mainHand.begin());
			}
			else if ((opponentHand.mainHand[0].getCardValue()) > (playerHand.mainHand[0].getCardValue()))
			{
				opponentHand.mainHand.push_back(std::move(playerHand.mainHand[0]));
				opponentHand.mainHand.push_back(std::move(opponentHand.mainHand[0]));
				playerHand.mainHand.erase(playerHand.mainHand.begin());
				opponentHand.mainHand.erase(opponentHand.mainHand.begin());
			}
			
			else if ((opponentHand.mainHand[0].getCardValue()) == (playerHand.mainHand[0].getCardValue()))
			{	
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
	numberOfWars += 1;
	
	playerHand.mainHand[2].cardFaceUp = true;
	opponentHand.mainHand[2].cardFaceUp = true;
}