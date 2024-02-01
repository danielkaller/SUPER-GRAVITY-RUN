#include "../include/Game.hpp"
#include "../include/SplashState.hpp"
#include <iostream>


Game::Game(int width, int height, std::string title)
{
    _data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);

    _data->machine.AddState(StateRef(new SplashState(_data)));
    
    this->Run();

    _data->window.close();

    _data.reset();
    // vi testa här 
}

void Game::Run()
{
    

    float newTime, frameTime;

    float currentTime = this->_clock.getElapsedTime().asSeconds();
    float accumulator = 0.0f;

    while (this->_data->window.isOpen())
    {
        this->_data->machine.ProcessStateChanges();

        newTime = this->_clock.getElapsedTime().asSeconds();
        frameTime = newTime - currentTime;

        if (frameTime > 0.25f)
        {
            frameTime = 0.25f;
        }

        currentTime = newTime;
        accumulator += frameTime;

        while (accumulator >= dt)
        {
            this->_data->machine.GetActiveState()->HandleInput();
            this->_data->machine.GetActiveState()->Update(dt);

            accumulator -= dt;
        }
        
        this->_data->machine.GetActiveState()->Draw();
    }

}
