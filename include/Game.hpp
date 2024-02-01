#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"


/**
 * A structure to represent SFML functions
*/
struct GameData
{
    StateMachine machine;       /**< SFML machine */
    sf::RenderWindow window;    /**< SFML window */
    AssetManager assets;        /**< AssetManager assets */
    InputManager input;         /**< InputManager input */
};

typedef std::shared_ptr<GameData> GameDataRef;  /*!< Name change for shared pointer */

/**
 * Represents a running Game
 */
class Game
{
public:

    /**
     * Game constructor
     *@param width Width of screen displaying SFML content
     *@param height Height of screen displaying SFML content
     *@param title Title of screen displaying SFML content
     */
    Game(int width, int height, std::string title);

    /**
     * Game destructor
     */
    ~Game() = default;

private:
    // Updates run at 60 per second.
    const float dt = 1.0f / 60.0f;                      /*!< Float that determine how many times the game will update */
    sf::Clock _clock;                                   /*!< SFML clock, used to determine how many seconds has passed in the game */
    GameDataRef _data = std::make_shared<GameData>();   /*!< shared pointer of Struct GameDataRef */

    /**
     * Private Function for running game
     */
    void Run();
};
