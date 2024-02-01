#pragma once
#include <string>
#include "Definitions.hpp"
#include "Game.hpp"
using std::string;

/**
 * Represents a Object
 */
class Object
{
    public:
       /**
        * Object constructor
        * @param data Refrence to a struct that contains SFML functions
        * @param pos_x The position of x-axis the Object should spawn at
        * @param pos_y The position of y-axis the Object should spawn at
        * @param name The name of the Object
        * @param on_roof Check if Object is placed on the roof or not, default value is false
        */
        Object(GameDataRef data, float pos_x, float pos_y, string const name, bool const on_roof = false);

        /**
         * Objects virtual destructor
         */
        virtual ~Object() = default;

        /**
         * Get Position of x-axis of an Object
         * @return Position of x-axis
        */
        float getPosx();

        /**
         * Get Position of y-axis of an Object
         * @return Position of y-axis
        */
        float getPosy();

        /**
         * Get Position of y-axis of an Object
         * @return Position of y-axis
        */
        string getName();
        
        /**
         * Get boolean on_roof
         * @return True or False if Object is on_roof
        */
        bool getOnRoof();

        /**
         * Get if Object is alive or dead
         * @return True or False if Object is is_alive
        */
        void dead();
        
        GameDataRef _data;      /*!< Refrence to a struct that contains sfml functions */
        float pos_x;            /*!< The position of x-axis the Object should spawn at */
        float pos_y;            /*!< The position of y-axis the Object should spawn at */
        int width;              /*!< The width of the Object */
        int height;             /*!< The height of the Object */
        string const name;      /*!< The name of the Object */

        bool is_alive;          /*!< Boolean if Object is alive */
        bool on_roof;           /*!< Boolean if Object is on roof */

        

        sf::Texture texture;    /*!< SFML texture of Object */
        sf::Sprite sprite;      /*!< SFML sprite of Object */
};