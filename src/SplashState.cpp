//#pragma once

#include "../include/SplashState.hpp"
//#include "MainMenuState.hpp"
#include "../include/Definitions.hpp"

//#include <iostream>


SplashState::SplashState(GameDataRef data) : _data(data)
{

}

void SplashState::Init()
{
    this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

    _splashBackground.setTexture(this->_data->assets.GetTexture("Splash State Background"));

    //Kolla detta
    sf::Vector2f targetSize(SCREEN_WIDTH, SCREEN_HEIGHT); 
	this->_splashBackground.setScale(targetSize.x / _splashBackground.getLocalBounds().width, targetSize.y / _splashBackground.getLocalBounds().height);
    // Kolla detta
}

void SplashState::HandleInput()
{
    sf::Event event;

    while (this->_data->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            this->_data->window.close();
        }
    }
}

void SplashState::Update(float dt)
{
    dt = dt;
    if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
    {
        // Switch To Main Menu
        
        this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
    }
}

void SplashState::Draw()
{
    
    this->_data->window.clear(sf::Color::Red);

    this->_data->window.draw( this->_splashBackground );

    this->_data->window.display();
}
