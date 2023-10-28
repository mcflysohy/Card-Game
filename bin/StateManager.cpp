#include "StateManager.hpp"

void StateManager::addState(std::unique_ptr<State> state, bool replacing)
{
	this->isAdding = true;
	this->isReplacing = replacing;

	this->newState = std::move(state);
}

void StateManager::removeState()
{
	this->isRemoving = true;
}

void StateManager::handleStateChanges()
{
	if (this->isRemoving && !this->allStatesOnStack.empty())
	{
		this->allStatesOnStack.pop();

		if (!allStatesOnStack.empty())
		{
			this->allStatesOnStack.top()->resume();
		}

		this->isRemoving = false;
	}

	if (this->isAdding)
	{
		if (!this->allStatesOnStack.empty())
		{
			if (this->isReplacing)
			{
				this->allStatesOnStack.pop();
			}
			else
			{
				this->allStatesOnStack.top()->pause();
			}
		}

		this->allStatesOnStack.push(std::move(this->newState));
		this->allStatesOnStack.top()->init();
		this->isAdding = false;
	}
}

std::unique_ptr<State> &StateManager::getActiveState()
{
	return this->allStatesOnStack.top();
}