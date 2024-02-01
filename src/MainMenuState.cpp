//#pragma once

#include <sstream>
#include "../include/MainMenuState.hpp"


MainMenuState::MainMenuState(GameDataRef data) : _data(data)
{

}

void MainMenuState::Init()
{
    this->_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
    this->_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
    this->_data->assets.LoadTexture("Level Selector", LEVEL_SELECTOR_FILEPATH);
    this->_data->assets.LoadTexture("Controls", CONTROLS_FILEPATH);

    _menuBackground.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
    
    sf::Vector2f targetSize(SCREEN_WIDTH, SCREEN_HEIGHT); 
	this->_menuBackground.setScale(targetSize.x / _menuBackground.getLocalBounds().width, targetSize.y / _menuBackground.getLocalBounds().height);
    
    _title.setTexture(this->_data->assets.GetTexture("Game Title"));
    _levelSelector.setTexture(this->_data->assets.GetTexture("Level Selector"));
    _controls.setTexture(this->_data->assets.GetTexture("Controls"));
    
    _title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), (0 + (_title.getGlobalBounds().height * 0.5)));
    _levelSelector.setPosition((SCREEN_WIDTH / 2) - (_levelSelector.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 3) - (_levelSelector.getGlobalBounds().height / 2));
    _controls.setPosition((SCREEN_WIDTH / 2) - (_controls.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_controls.getGlobalBounds().height / 2));
    
}

void MainMenuState::HandleInput()
{
    sf::Event event;

    while (this->_data->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            this->_data->window.close();
        }

        if (this->_data->input.IsSpriteClicked(this->_levelSelector, sf::Mouse::Left, this->_data->window))
        {
            // Switch To LevelSelctor
            //this->_data->machine.AddState(StateRef(new MainMenuState(_data)), false); //
            this->_data->machine.AddState(StateRef(new LevelSelectorState(_data)), true);
        }

        if (this->_data->input.IsSpriteClicked(this->_controls, sf::Mouse::Left, this->_data->window))
        {
            // Switch To Controls
            //this->_data->machine.AddState(StateRef(new MainMenuState(_data)), false); //
            this->_data->machine.AddState(StateRef(new ControlsState(_data)), true);
        }


    }
}

void MainMenuState::Draw()
{
    
    this->_data->window.clear(sf::Color::Red);

    
    
    this->_data->window.draw(this->_menuBackground);
    this->_data->window.draw(this->_title);
    this->_data->window.draw(this->_levelSelector);
    this->_data->window.draw(this->_controls);
    sf::View MenuView;
	MenuView.reset(sf::FloatRect(0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT));
	this->_data->window.setView(MenuView);
    this->_data->window.display();
}
