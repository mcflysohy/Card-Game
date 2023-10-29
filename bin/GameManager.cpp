#include "GameManager.hpp"

void GameManager::addState(std::unique_ptr<GameState> state, bool replacing)
{
	this->isAdding = true;
	this->isReplacing = replacing;

	this->newState = std::move(state);
}

void GameManager::removeState()
{
	this->isRemoving = true;
}

void GameManager::handleStateChanges()
{
	if (this->isRemoving && !this->gameStack.empty())
	{
		this->gameStack.pop();

		if (!gameStack.empty())
		{
			this->gameStack.top()->resume();
		}

		this->isRemoving = false;
	}

	if (this->isAdding)
	{
		if (!this->gameStack.empty())
		{
			if (this->isReplacing)
			{
				this->gameStack.pop();
			}
			else
			{
				this->gameStack.top()->pause();
			}
		}

		this->gameStack.push(std::move(this->newState));
		this->gameStack.top()->init();
		this->isAdding = false;
	}
}

std::unique_ptr<GameState> &GameManager::getActiveState()
{
	return this->gameStack.top();
}
