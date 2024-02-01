#pragma once

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "Game.hpp"

using std::string;

/**
 * Represents a Winstate. Happens if a level is won
 */
class WinState : public State
{
public:

    /**
     * WinStates constructor
     *
     *@param data Refrence to a struct that contains sfml functions
     *@param level Name of the level to replay
     *@param time Time it took to finish the level
     */
    WinState(GameDataRef data, string level, float time);
    
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

    float timeElapsed; /*!< float to display time to beat a level */

    string levelFile; /*!< Filename of level */

    sf::Text _text; /*!< Text to write on the screen */
    sf::Font font; /*!< Font to choose font */
    
    sf::Sprite _gameOverBackground; /*!< Sprite for win background */
    sf::Sprite _return; /*!< Sprite for return button */
    sf::Sprite _playAgain; /*!< Sprite for play again button */
    sf::Sprite _time; /*!< Sprite for showing time text */

};

