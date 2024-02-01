#pragma once

#include "SFML/Graphics.hpp"

/**
 * Class for mouse inputs
 */

class InputManager
{
public:

    /**
     * InputManagers constructor
     */
    InputManager() {}

    /**
     * InputManagers destructor
     */
    ~InputManager() = default;

    /**
     * Cheks if a sprite is clicked
     *
     * @param object Selected object
     * @param button Cliked butto
     * @param window Rendered Window
     *
     * @return True or False if Sprite is clicked
     */
    bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

    /**
     * Gets the position of the mouse
     *
     * @param window Rendered Window
     */
    sf::Vector2i GetMousePosition(sf::RenderWindow &window);
};
