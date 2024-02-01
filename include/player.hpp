#pragma once
#include "entity.hpp"
#include "object.hpp"
#include <SFML/Graphics.hpp>

using std::string;

class Enemy1;

/**
 * Represents a player
 */

class Player : public Entity, public sf::Sprite
{
public:
    /**
     * Players constructor
     * @param data Refrence to a struct that contains SFML functions
     * @param pos_x The position of x-axis the player should spawn at
     * @param pos_y The position of y-axis the player should spawn at
     * @param name The name of the player
     */
    Player(GameDataRef data, float pos_x, float pos_y, string const name);

    /**
     * Players destructor
     */
    ~Player() = default;

    /**
     * Get Players sprite
     * @return SFML Sprite of player
     */
    sf::Sprite getSprite();
    
    /**
     * Draws the sprite of Player
     */
    void draw();
    
    /**
     * Checks collision between Player and a vector of objects
     * @param vecObjects A vector of objects
     * @param time The amount of time that has passed since GameState was oppend
     */
    template <class T>
    void checkCollision(vector<T> vecObjects, float const time);

    /**
     * Updates the Player
     * @param vecObjects A vector that cointains pointers of objects
     * @param vecEnemy1 A vector that cointains pointers of Enemy1 objects
     * @param time The amount of time that has passed since GameState was oppend
     */
    void update(vector<Object*> vecObjects, vector<Enemy1*> vecEnemy1, float const time);

    /**
     * Takes keypressed and calls function based on result
     * @param time The amount of time that has passed since GameState was oppend
     */
    void move(float const time);

    /**
     * Function for Player to jump
     * @param time The amount of time that has passed since GameState was oppend
     */
    void jump(float const time);

    /**
     * Function for Player to turn gravity on or off
     * @param time The amount of time that has passed since GameState was oppend
     */
    void gravityChange(float const time);

    /**
     * Function for Player to move left
     */
    void left();

    /**
     * Function for Player to move right
     */
    void right();

    /**
     * Function for Player to change texture on sprite. Depending on curr_rotation
     */
    void animate();

private:
    bool is_jumping{false};     /*!< Boolean if Player is jumping */
    float jump_time;            /*!< Float that saves the time when player is activating the function jump */
    bool is_changingGravity;    /*!< Boolean if Player is currently changing gravity on or off */
    float gravity_time;         /*!< Float that saves the time when player is activating the function gravityChange */
    bool gravityOff;            /*!< Boolean if Players gravity is on or off */
};