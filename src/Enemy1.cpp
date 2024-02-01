#include "../include/Enemy1.hpp"

Enemy1::Enemy1(GameDataRef data, float pos_x, float pos_y, string const name) : Entity{data, pos_x, pos_y, name}
{
    width = 96;
    height = 96;

    on_ground = false;
    standing_on_block = false;

    curr_rotation = "left";

    is_alive = true;

    xspeed = 3;
    yspeed = 3;

    sprite.setTexture(this->_data->assets.GetTexture("Enemy1"));
    sprite.setScale(1, 1);

    sprite.setOrigin(0.f, 0.f);
    sprite.setTextureRect(sf::IntRect(0,0, width, height));
    sprite.setPosition(sf::Vector2f(pos_x, pos_y));
}

bool Enemy1::playerNearby(int const playerPosX)
{
    if((getPosx() > playerPosX && (getPosx() - SCREEN_WIDTH/2) < playerPosX) ||
        (getPosx() < playerPosX && getPosx() + SCREEN_WIDTH/2 > playerPosX))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Enemy1::checkCollision(vector<Object*> vecObjects)
{
    standing_on_block = false;
    for(Object* obj : vecObjects)
    {
        //Checking collision moving right
        if(sprite.getPosition().x <= obj->getPosx() + OBJECT_WIDTH && sprite.getPosition().x + sprite.getTexture()->getSize().x > obj->getPosx() 
            && (sprite.getPosition().y + sprite.getTexture()->getSize().y) >= (obj->getPosy() + OBJECT_HEIGHT) 
                && sprite.getPosition().y <= obj->getPosy() && curr_rotation == "right")
        {
            if(obj->getName() == "Block")
            {
                curr_rotation = "left";
                this->pos_x = pos_x - 10;
            }
        }
        //Checking collision moving left
        else if(sprite.getPosition().x >= obj->getPosx() && sprite.getPosition().x <= obj->getPosx() + OBJECT_WIDTH 
            && (sprite.getPosition().y + sprite.getTexture()->getSize().y) >= (obj->getPosy() + OBJECT_HEIGHT) 
                && sprite.getPosition().y <= obj->getPosy() && curr_rotation == "left")
        {
            if(obj->getName() == "Block")
            {
                curr_rotation = "right";
                this->pos_x = pos_x + 10;
            }
        }
        //Checking collision top Y
        else if(sprite.getPosition().y >= obj->getPosy() && sprite.getPosition().y <= obj->getPosy() + OBJECT_HEIGHT 
            && sprite.getPosition().x < (obj->getPosx() + OBJECT_WIDTH) 
                && (sprite.getPosition().x + sprite.getTexture()->getSize().x) >= obj->getPosx())
        {
            //Checking type of object
            if(obj->getName() == "Block")
            {
                this->pos_y = obj->getPosy() + OBJECT_HEIGHT;
                yspeed = 0;
                on_ground = false;
            }
        }

        //Checking collision bottom Y
        else if(sprite.getPosition().y + sprite.getTexture()->getSize().y >= obj->getPosy() 
            && sprite.getPosition().y < obj->getPosy() && sprite.getPosition().x < (obj->getPosx() + OBJECT_WIDTH) 
                && (sprite.getPosition().x + sprite.getTexture()->getSize().x) >= obj->getPosx())
        {
            //Checking type of object
            if(obj->getName() == "Block")
            {
                this->pos_y = obj->getPosy() - sprite.getTexture()->getSize().y;
                standing_on_block = true;
                on_ground = true;
            }
        }
    }
    if (!standing_on_block)
    {
        on_ground = false;
    }
}

void Enemy1::update(vector<Object*> vecObjects, int const playerPosX)
{
    if(is_alive)
    {
    if(playerNearby(playerPosX))
    {
        checkCollision(vecObjects);
        move();
        if(!on_ground)
        {
            yspeed += 0.01;
            pos_y = pos_y + yspeed;
        }
        this->sprite.setPosition(this->pos_x, this->pos_y);
    }
    }
    else
    {
        is_alive = false;
        pos_y = POSITION_OUTSIDE_MAP_Y;
        pos_x = POSITION_OUTSIDE_MAP_X;
    }
}

void Enemy1::move()
{
    if(curr_rotation == "right")
    {
        pos_x = pos_x + xspeed;
    }
    else
    {
        pos_x = pos_x - xspeed;
    }
}

void Enemy1::draw()
{
    if(is_alive)
    {
        _data->window.draw(sprite);
    }
}