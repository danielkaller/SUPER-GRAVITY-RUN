#pragma once

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "Game.hpp"
#include "Definitions.hpp"
#include "MainMenuState.hpp"
#include "GameOverState.hpp"
#include "WinState.hpp"
#include "player.hpp"
#include "block.hpp"
#include "Enemy1.hpp"
#include "spike.hpp"
#include "spaceship.hpp"

/**
 * Represents the game screen
 */

class GameState : public State
{
public:
    
    /**
     * GameStates constructor
     *
     *@param data Refrence to a struct that contains sfml functions
     *@param level String to identify wich level to play
     */
    GameState(GameDataRef data, string level);

    /**
     * Funtion that loads the map the users have chosen
     *
     *@param filename Name of the file to play
     */
    void Map(string filename);
    
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
     * @param dt Handels time
     */
    void Update(float dt);

    /**
     * Function that handels what the player sees
     */
    void Draw();

    /**
     * Template Functions that take a vector and deletes all its content
     * @param game_objects a vector of game objects
     */
    template<class T>
    void deleteObjects(std::vector<T> & game_objects);

private:
    GameDataRef _data; /*!< Refrence to a struct that contains sfml functions */

    vector<Enemy1*> vecEnemies1; /*!< Vector for enemy pointers */

    vector<Object*> vecObjects; /*!< Vector for object pointers */

    sf::Sprite _gameBackground; /*!< First of two sprites for the game background */
    sf::Sprite _gameBackground2; /*!< Second of two sprites for the game background */

    sf::Clock _clock; /*!< Clock to keep time */

    string levelFile; /*!< Filename of level */

    int x = 0; /*!< Decides where the first background spawns */
    int x2 = (_gameBackground.getLocalBounds().width);  /*!< Decides where the second background spawns */

    Player* p1; /*!< Player pointer */
    Object* o1; /*!< Object pointer */
    Block* b1; /*!< Block pointer */
    Spike* s1; /*!< Spike pointer */
    Spaceship* g1; /*!< Spaceship pointer */
    Enemy1* e1; /*!< Enemy pointer */
};
