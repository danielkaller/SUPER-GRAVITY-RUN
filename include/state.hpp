#pragma once

/**
 * Represents an average state
 */

class State
{
public:

    /**
     * States constructor
     */
    State() = default;

    /**
     * States destructor
     */
    virtual ~State() = default;

    /**
     * Initialiser function
     */
    virtual void Init() = 0;

    /**
     * Funtion that handels the state inputs
     */
    virtual void HandleInput() = 0;

    /**
     * Function that handles the update of the state
     *
     *@param dt handels time
     */
    virtual void Update(float dt){dt = dt;}

    /**
     * Function that handels what the player sees
     */
    virtual void Draw() = 0;
};
