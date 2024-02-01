#pragma once
#include "object.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
using std::vector;

/**
 * Represents an Entity
 */
class Entity : public Object
{
    public:
        /**
         * Entity constructor
         * @param data Refrence to a struct that contains SFML functions
         * @param pos_x The position of x-axis the Entity should spawn at
         * @param pos_y The position of y-axis the Entity should spawn at
         * @param name The name of the Entity
         */
        Entity(GameDataRef data, float pos_x, float pos_y, string const name);

        /**
         * Entity virtual destructor
         */
        virtual ~Entity() = default;

        /**
         * Check if Entity is outside of map and should be killed
         * @param y The position of y-axis the Entity has
         * @return false or true for Entity outside map
         */
        bool outsideMapCheck(int const y);
        
        /**
         * Virtual function to draw sprite
         */
        virtual void draw() = 0;

        std::vector<sf::Texture> animations;    /*!< Vector for textures of Entity */
        float yspeed;                           /*!< Float of Entity speed y */
        float xspeed;                           /*!< Float of Entity speed x */
        bool on_ground{false};                  /*!< Boolean if Entity is on block */
        bool standing_on_block;                 /*!< Boolean if Entity is standing on block */
        string curr_rotation;                   /*!< String of Entity rotation left or right */
};