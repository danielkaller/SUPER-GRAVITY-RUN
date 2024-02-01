#include "../include/player.hpp"
#include "../include/object.hpp"
//#include "block.hpp"
#include "../include/Enemy1.hpp"
#include <iostream>
//using std::cout;
//using std::endl;

Player::Player(GameDataRef data, float pos_x, float pos_y, string const name) : Entity{data, pos_x, pos_y, name}, is_jumping{is_jumping}, jump_time{jump_time}, is_changingGravity{is_changingGravity}, gravity_time{gravity_time}
{
    pos_x = 200;
    pos_y = 200;

    width = 96;
    height = 126;

    curr_rotation = "right";

    standing_on_block = false;
    is_alive = true;
    is_jumping = false;
    on_ground = false;
    is_changingGravity = false;
    gravityOff = false;

    yspeed = 0;
    xspeed = 10;

    animations.push_back(this->_data->assets.GetTexture("Player left roof"));
    animations.push_back(this->_data->assets.GetTexture("Player right roof"));
    animations.push_back(this->_data->assets.GetTexture("Player right"));
    animations.push_back(this->_data->assets.GetTexture("Player left"));
    sprite.setTexture(animations.at(2));
    sprite.setScale(1, 1);

    sprite.setOrigin(0.f, 0.f);
    sprite.setTextureRect(sf::IntRect(0,0, width, height));
    sprite.setPosition(sf::Vector2f(pos_x, pos_y));
}

sf::Sprite Player::getSprite() {
    return sprite;
}

void Player::draw()
{
    if(is_alive)
    {
        _data->window.draw(sprite);
    }
}

template <class T>
void Player::checkCollision(vector<T> vecObjects, float const time)
{
    standing_on_block = false;
    for(T obj : vecObjects)
    {
        //Checking collision moving right
        if(sprite.getPosition().x <= obj->getPosx() && sprite.getPosition().x + sprite.getTexture()->getSize().x > obj->getPosx() 
            && ((sprite.getPosition().y + sprite.getTexture()->getSize().y) >= (obj->getPosy() + OBJECT_HEIGHT) 
                && sprite.getPosition().y <= obj->getPosy()) && curr_rotation == "right")
        {
            if(obj->getName() == "Block")
            {
                xspeed = 0;
                this->pos_x = pos_x - 10;
            }
            else if(obj->getName() == "Enemy1")
            {
                is_alive = false;
            }
            else if(obj->getName() == "Spike")
            {
                is_alive = false;
            }
        }
        //Checking collision moving left
        else if(sprite.getPosition().x >= obj->getPosx() && sprite.getPosition().x <= obj->getPosx() + OBJECT_WIDTH 
            && (sprite.getPosition().y + sprite.getTexture()->getSize().y) >= (obj->getPosy() + OBJECT_HEIGHT) 
                && sprite.getPosition().y <= obj->getPosy() && curr_rotation == "left")
        {
            if(obj->getName() == "Block")
            {
                xspeed = 0;
                this->pos_x = obj->pos_x + OBJECT_WIDTH;
            }
            else if(obj->getName() == "Enemy1")
            {
                is_alive = false;
            }
            else if(obj->getName() == "Spike")
            {
                is_alive = false;
            }
        }

        //Checking collision top Y
        else if(sprite.getPosition().y >= obj->getPosy() && sprite.getPosition().y <= obj->getPosy() + OBJECT_HEIGHT 
            && sprite.getPosition().x < (obj->getPosx() + OBJECT_WIDTH) 
                && (sprite.getPosition().x + sprite.getTexture()->getSize().x) >= obj->getPosx())
        {
            //Checking type of object
            if(!gravityOff)
            {
                if(obj->getName() == "Block")
                {
                    this->pos_y = obj->getPosy() + OBJECT_HEIGHT;
                    yspeed = 0;
                    on_ground = false;
                }
            }
            else
            {
                if(obj->getName() == "Block")
                {
                    this->pos_y = obj->getPosy() + OBJECT_HEIGHT;
                    standing_on_block = true;
                    on_ground = true;
                    is_jumping = false;
                }
                else if(obj->getName() == "Enemy1")
                {
                    obj->is_alive = false;
                    jump(time);
                }
                else if(obj->getName() == "Spike")
                {
                    is_alive = false;
                }
            }
        }

        //Checking collision bottom Y
        else if(sprite.getPosition().y + sprite.getTexture()->getSize().y >= obj->getPosy() && sprite.getPosition().y < obj->getPosy() 
            && sprite.getPosition().x < (obj->getPosx() + OBJECT_WIDTH) 
                && (sprite.getPosition().x + sprite.getTexture()->getSize().x) >= obj->getPosx() && on_ground == false)
        {
            //Checking type of object
            if(!gravityOff)
            {
                if(obj->getName() == "Block")
                {
                    this->pos_y = obj->getPosy() - sprite.getTexture()->getSize().y;
                    standing_on_block = true;
                    on_ground = true;
                    is_jumping = false;
                }
                else if(obj->getName() == "Enemy1")
                {
                    obj->is_alive = false;
                    jump(time);
                }
                else if(obj->getName() == "Spike")
                {
                    is_alive = false;
                }
            }
            else
            {
                if(obj->getName() == "Block")
                {
                    this->pos_y = obj->getPosy() - sprite.getTexture()->getSize().y;
                    yspeed = 0;
                    on_ground = false;
                }
                else if(obj->getName() == "Enemy1")
                {
                    is_alive = false;
                }

            }
        }

    }
    if (!standing_on_block)
    {

        on_ground = false;
    }
}


void Player::update(vector<Object*> vecObjects, vector<Enemy1*> vecEnemies1, float const time)
{
    checkCollision(vecEnemies1, time);
    checkCollision(vecObjects, time);

    move(time);
    if(on_ground == false)
    {
        if(is_jumping)
        {
            if(jump_time + 0.5 < time)
            {
                if(gravityOff)
                {
                    yspeed -= 1;
                }
                else
                {
                   yspeed += 1; 
                }
                pos_y = pos_y + yspeed;
            }
            else
            {
                jump(time);
            }
        }
        else
        {
            if(gravityOff)
            {
                yspeed = 0;
                yspeed -= 15;
            }
            else
            {
                yspeed = 0;
                yspeed += 15;
            }
            pos_y = pos_y + yspeed;
        }

    if(is_changingGravity)
    {
        if(gravity_time + 2 < time)
        {
            is_changingGravity = false;
        }
    }
    }
    
    sprite.setPosition(this->getPosx(), this->getPosy());

    if(outsideMapCheck(pos_y) == true)
    {
        is_alive = false;
    }
}

void Player::move(float time)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) && is_changingGravity == false)
    {
        on_ground = false;
        gravityChange(time);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        left();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        right();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && on_ground == true)
    {
        jump(time);
    }
}

void Player::jump(float time)
{
    if(is_jumping == false)
    {
        yspeed = 0;
        jump_time = time;
    }
    if(gravityOff)
    {
        yspeed = 8;
    }
    else
    {
        yspeed = -8;
    }
    pos_y = pos_y + yspeed;
    on_ground = false;
    is_jumping = true;
}

void Player::gravityChange(float time)
{
    if(is_changingGravity == false)
    {
        gravity_time = time;
    }
    if(gravityOff)
    {
        gravityOff = false;
    }
    else
    {
        gravityOff = true;
    }
    is_changingGravity = true;
    animate();
}

void Player::left()
{
    xspeed = 10;
    pos_x = pos_x - xspeed;
    curr_rotation = "left";
    animate();
    
}

void Player::right()
{
    xspeed = 10;
    pos_x = pos_x + xspeed;
    curr_rotation = "right";
    animate();
}

void Player::animate()
{
    if(curr_rotation == "right")
    {
        if(gravityOff)
        {
            sprite.setTexture(animations.at(1));
        }
        else
        {
            sprite.setTexture(animations.at(2));
        }
    }
    else
    {
        if(gravityOff)
        {
            sprite.setTexture(animations.at(0));
        }
        else
        {
            sprite.setTexture(animations.at(3));
        }
    }
}