#pragma once

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "Game.hpp"
#include "MainMenuState.hpp"

/**
 * Represents the splash screen
 */

class SplashState : public State
{
public:

    /**
     * SplashStates constructor
     *
     *@param data Refrence to a struct that contains sfml functions
     */
    SplashState(GameDataRef data);

      
    /**
     * Initialiser function
     */
    void Init();

    /**
     * Funtion that handels the state inputs
     */
    void HandleInput();

    /**
     * Function that handles the update of the state
     *
     *@param dt Handels time
     */
    void Update(float dt);

    /**
     * Function that handels what the player sees
     */
    void Draw();

private:
    GameDataRef _data; /*!< Refrence to a struct that contains sfml functions */

    sf::Clock _clock;  /*!< SFML clock, used to determine how many seconds has passed in the splash state */

    sf::Sprite _splashBackground; /*!< Sprite for SplashState background */
};
