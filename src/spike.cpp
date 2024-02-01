#include "../include/spike.hpp"

Spike::Spike(GameDataRef data, float pos_x, float pos_y, string const name, bool on_roof) : Object{data, pos_x, pos_y, name, on_roof}
{
    width = 96;
    height = 45;
    
    if(on_roof)
    {
        sprite.setTexture(this->_data->assets.GetTexture("Upside Down Spike"));
    }
    else
    {
        sprite.setTexture(this->_data->assets.GetTexture("Spike"));
    }
    sprite.setTextureRect(sf::IntRect(0,0, width, height));
    sprite.setPosition(sf::Vector2f(pos_x, pos_y));
}

void Spike::draw()
{
    _data->window.draw(sprite);
}