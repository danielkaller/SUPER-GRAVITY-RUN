#pragma once

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "Game.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"

using std::string;

/**
 * Represents the game over screen
 */

class GameOverState : public State
{
public:

    /**
     * GameOverStates constructor
     *
     *@param data Refrence to a struct that contains sfml functions
     *@param level Name of the level to restart
     */
    GameOverState(GameDataRef data, string level);
    
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

    string levelFile; /*!< Filename of level */

    sf::Sprite _gameOverBackground; /*!< Sprite for GameOver background */
    sf::Sprite _return; /*!< Sprite for return button */
    sf::Sprite _tryAgain; /*!< Sprite for try again button */
};