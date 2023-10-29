#ifndef STATE_MANAGER_HPP_INCLUDED
#define STATE_MANAGER_HPP_INCLUDED

#include <memory>
#include <stack>

#include "GameState.hpp"

class GameManager
{
public:
	GameManager() {};
	~GameManager() {};

	void addState(std::unique_ptr<GameState> state, bool replacing = true);
	void removeState();

	void handleStateChanges();

	std::unique_ptr<State> &getActiveState();

private:
	std::stack<std::unique_ptr<GameState> gameStack;
	std::unique_ptr<GameState> newState;

	bool isRemoving;
	bool isAdding; 
	bool isReplacing;
};

#endif
