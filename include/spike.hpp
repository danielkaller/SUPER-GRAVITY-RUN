#pragma once
#include "object.hpp"
#include <SFML/Graphics.hpp>

/**
 * Represents an Spike
 */
class Spike : public Object
{
    public:
        /**
         * Spike constructor
         * @param data Refrence to a struct that contains SFML functions
         * @param pos_x The position of x-axis the Spike should spawn at
         * @param pos_y The position of y-axis the Spike should spawn at
         * @param name The name of the Spike
         * @param on_roof Check if Spike is placed on the roof or not, default value is false
         */
        Spike(GameDataRef data, float pos_x, float pos_y, string const name, bool const on_roof = false);
        
        /**
         * Spike destructor
         */
        ~Spike() override = default;

        /**
         * Draws the sprite of Spike
         */
        void draw();
};