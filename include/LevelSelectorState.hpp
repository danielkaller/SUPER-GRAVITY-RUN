#pragma once

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "Game.hpp"
#include "MainMenuState.hpp"
#include "Definitions.hpp"
#include "GameState.hpp"

/**
 * Represents the level selector screen
 */

class LevelSelectorState : public State
{
public:

    /**
     * LevelSelectorStates constructor
     *
     *@param data Refrence to a struct that contains sfml functions
     */
    LevelSelectorState(GameDataRef data);

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

    sf::Sprite _levelBackground; /*!< Sprite for LevelSelector background */
    sf::Sprite _levelSelector; /*!< Sprite for LevelSelector titel */
    sf::Sprite _level1; /*!< Sprite for level1 picture  */
    sf::Sprite _level3; /*!< Sprite for level2 picture */
    sf::Sprite _level2; /*!< Sprite for level3 picture */
    sf::Sprite _back; /*!< Sprite for back button */
};