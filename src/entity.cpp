#include "../include/entity.hpp"
#include <iostream>

using std::cout;
using std::endl;

Entity::Entity(GameDataRef _data, float pos_x, float pos_y, string const name) : Object{_data, pos_x, pos_y, name}
{

}

bool Entity::outsideMapCheck(int const y)
{
    if(y >= (SCREEN_HEIGHT * 1.5) || y <= (-SCREEN_HEIGHT * 1.5))
    {
       return true;
    }
    else
    {
        return false;
    }
}