#include "../include/spaceship.hpp"

Spaceship::Spaceship(GameDataRef data, float pos_x, float pos_y, string const name) : Object{data, pos_x, pos_y, name}
{
    width = 192;
    height = 331;


    sprite.setTexture(this->_data->assets.GetTexture("Spaceship"));
    sprite.setTextureRect(sf::IntRect(0,0, width, height));
    sprite.setPosition(sf::Vector2f(pos_x, pos_y));
}

void Spaceship::draw()
{
    _data->window.draw(sprite);
}