#pragma once
#include "entity.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>

using std::string;


/**
 * Represents an Entity
 */
class Enemy1 : public Entity, public sf::Sprite
{
public:
        /**
         * Enemy1 constructor
         * @param data Refrence to a struct that contains SFML functions
         * @param pos_x The position of x-axis the Enemy1 should spawn at
         * @param pos_y The position of y-axis the Enemy1 should spawn at
         * @param name The name of the Enemy1
         */
        Enemy1(GameDataRef data, float pos_x, float pos_y, string const name);

        /**
         * Enemy1 destructor
         */
        ~Enemy1() override = default;

        bool playerNearby(int const playerPosX);

        /**
         * Checks collision between Enemy1 and a vector of objects
         * @param vecObjects A vector of objects
         */
        void checkCollision(vector<Object*> vecObjects);

        /**
         * Updates Enemy1
         * @param vecObjects A vector that cointains pointers of Objects
         * @param playerPosX Float of a Player objects x-axis
         */
        void update(vector<Object*> vecObjects, int const playerPosX);

        /**
         * Moves Enemy1 left and right depending on last collision with a Block
         */
        void move();
        
        /**
         * Draws the sprite of Enemy1
         */
        void draw();
};