#pragma once

#include <memory>
#include <stack>

#include "state.hpp"


typedef std::unique_ptr<State> StateRef; /*!< A reference to class state  */


/**
 * Represents a StateMachine which handles all the states
 */
class StateMachine
{
public:
    /**
     * StateMachine constructor
     */
    StateMachine() = default;
    
    /**
     * StateMachine destructor
     */
    ~StateMachine() = default;

    /**
     * Function that adds a new state
     * @param newState The state to be added
     * @param isReplacing Bool if the new statement is to replace the current one 
     */
    void AddState(StateRef newState, bool isReplacing = true);

    /**
     * Function that removes the current state
     */
    void RemoveState();

    // Run at start of each loop in Game.cpp

    /**
     * Function processes the changes between a new state and a old state
     */
    void ProcessStateChanges();
    
    /**
     * Function to get the current state
     * @return the current/active state
     */
    StateRef &GetActiveState();

private:


    std::stack<StateRef> _states; /*!< a stack that contains a reference of class State */
    StateRef _newState; /*!< a referens of class State */

    bool _isRemoving; /*!< Boolean to identify if a state should be removed */
    bool _isAdding; /*!< Boolean to identify if a state should be added */
    bool _isReplacing; /*!< Boolean to identify if a state should be replaced */
};
