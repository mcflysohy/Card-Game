#ifndef STATE_MANAGER_HPP_INCLUDED
#define STATE_MANAGER_HPP_INCLUDED

#include <memory>
#include <stack>

#include "State.hpp"

class StateManager
{
public:
	StateManager() {};
	~StateManager() {};

	void addState(std::unique_ptr<State> state, bool replacing = true);
	void removeState();

	void handleStateChanges();

	std::unique_ptr<State> &getActiveState();

private:
	std::stack<std::unique_ptr<State>> allStatesOnStack;
	std::unique_ptr<State> newState;

	bool isRemoving;
	bool isAdding;
	bool isReplacing;
};

#endif
