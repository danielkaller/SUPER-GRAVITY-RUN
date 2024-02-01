#include "object.hpp"
//#include "../Machine/Game.hpp"
#include <SFML/Graphics.hpp>


/**
 * Represents an Spaceship
 */
class Spaceship : public Object
{
    public:
        /**
         * Spaceship constructor
         * @param data Refrence to a struct that contains SFML functions
         * @param pos_x The position of x-axis the Spaceship should spawn at
         * @param pos_y The position of y-axis the Spaceship should spawn at
         * @param name The name of the Spaceship
         */
        Spaceship(GameDataRef data, float pos_x, float pos_y, string const name);

        /**
         * Spaceship destructor
         */
        ~Spaceship() override = default;
        
        /**
        * Draws the sprite of Spaceship
        */
        void draw();
};