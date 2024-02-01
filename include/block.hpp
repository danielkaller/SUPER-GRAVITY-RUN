#pragma once
#include "object.hpp"
#include <SFML/Graphics.hpp>

/**
 * Represents blocks
 */ 

class Block : public Object
{
public:

    /**
     * Blocks constructor
     * @param data Refrence to a struct that contains sfml functions
     * @param pos_x The position of x-axis the block should spawn at
     * @param pos_y The position of y-axis the block should spawn at
     * @param name The name of the block should spawn at
     * @param on_roof Boolian to deside if the block should spawn upsidedown
     */
    Block(GameDataRef data, float pos_x, float pos_y, string const name, 
        bool const on_roof = false);

    /**
     * Blocks destructor
     */
    ~Block() override = default;

    /**
     * Draws the sprite of Block
     */
    void draw();
};