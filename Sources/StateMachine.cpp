#include "StateMachine.h"

void StateMachine::addState(StateRef _newState, bool _isReplacing)
{
	this->isAdding = true;
	this->isReplacing = _isReplacing;

	this->newState = std::move(_newState);
}

void StateMachine::removeState()
{
	this->isRemoving = true;
}

void StateMachine::processStatesChanges()
{
	if (this->isRemoving && !this->statesStack.empty())
	{
		this->statesStack.pop();

		if (!this->statesStack.empty())
			this->statesStack.top()->resume();
		
		this->isRemoving = false;
	}
	
	if (this->isAdding)
	{
		if (!statesStack.empty())
		{
			if (this->isReplacing)
			{
				this->statesStack.pop();
			}
			else
				this->statesStack.top()->pause();			
		}
		this->statesStack.push(std::move(this->newState));
		this->statesStack.top()->init();
		this->isAdding = false;
	}
}

StateRef & StateMachine::getActiveState()
{
	return this->statesStack.top();
}
