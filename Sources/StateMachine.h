#ifndef STATEMACHINE
#define STATEMACHINE

#include <memory>
#include <stack>

#include "State.h"

typedef std::unique_ptr<State> StateRef;

class StateMachine
{
private:
	std::stack<StateRef> statesStack;
	StateRef newState;

	bool isReplacing;
	bool isAdding;
	bool isRemoving;

public:
	StateMachine() {}
	~StateMachine() {}

	void addState(StateRef _newState, bool _isReplacing = true);
	void removeState();

	void processStatesChanges();

	StateRef &getActiveState();
};

#endif // !STATEMACHINE
