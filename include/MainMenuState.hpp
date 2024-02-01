#pragma once

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "Game.hpp"
#include "ControlsState.hpp"
#include "LevelSelectorState.hpp"
#include "Definitions.hpp"
#include "GameState.hpp"

/**
 * Represents the main menu screen
 */

class MainMenuState : public State
{
public:
    /**
     * MainMenuStates constructor
     *
     *@param data Refrence to a struct that contains sfml functions
     */
    MainMenuState(GameDataRef data);

    

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

    sf::Sprite _menuBackground; /*!< Sprite for MainMenu background */
    sf::Sprite _title; /*!< Sprite for Game titel */
    sf::Sprite _levelSelector; /*!< Sprite for LevelSelector button */
    sf::Sprite _controls; /*!< Sprite for controls button */
};
