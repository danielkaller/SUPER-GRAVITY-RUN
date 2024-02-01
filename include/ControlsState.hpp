#pragma once

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "Game.hpp"
#include "MainMenuState.hpp"
#include "Definitions.hpp"

/**
 * Represents the controls screen
 */

class ControlsState : public State
{
public:

    /**
     * ControlsStates constructor
     *
     *@param data Refrence to a struct that contains sfml functions
     */
    ControlsState(GameDataRef data);

    /**
     * Initialiser function
     */
    void Init();

    /**
     * Funtion that handels the state inputs
     */
    void HandleInput();

    /**
     * Function that handels what the player sees
     */
    void Draw();

private:
    GameDataRef _data; /*!< Refrence to a struct that contains sfml functions */

    sf::Sprite _controlsBackground; /*!< Sprite for ControlsStates background */
    sf::Sprite _back; /*!< Sprite for back button */
    
};