#include "../include/block.hpp"

Block::Block(GameDataRef data, float pos_x, float pos_y, string const name, bool on_roof) : Object{data, pos_x, pos_y, name, on_roof}
{
    width = 96;
    height = 96;

    if(on_roof)
    {
        sprite.setTexture(this->_data->assets.GetTexture("Upside Down Block"));
    }
    else
    {
        sprite.setTexture(this->_data->assets.GetTexture("Block"));
    }

    sprite.setTextureRect(sf::IntRect(0,0, width, height));
    sprite.setPosition(sf::Vector2f(pos_x, pos_y));
}

void Block::draw()
{
    _data->window.draw(sprite);
}