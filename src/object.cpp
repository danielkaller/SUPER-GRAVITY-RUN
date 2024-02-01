#include "../include/object.hpp"

Object::Object(GameDataRef data, float pos_x, float pos_y, string const name, bool on_roof) : _data{data}, pos_x{pos_x}, pos_y{pos_y}, name{name}, on_roof{on_roof}
{

}

float Object::getPosx()
{
    return pos_x;
}

float Object::getPosy()
{
    return pos_y;
}

string Object::getName()
{
    return name;
}

bool Object::getOnRoof()
{
    return on_roof;
}

void Object::dead()
{
    is_alive = false;
}