#include <sstream>
#include "../include/ControlsState.hpp"

ControlsState::ControlsState(GameDataRef data) : _data(data)
{}

void ControlsState::Init()
{
    this->_data->assets.LoadTexture("Controls Background", CONTROLS_BACKGROUND_FILEPATH);
    this->_data->assets.LoadTexture("Back", BACK_FILEPATH);

    _controlsBackground.setTexture(this->_data->assets.GetTexture("Controls Background"));

    sf::Vector2f targetSize(SCREEN_WIDTH, SCREEN_HEIGHT); 
	this->_controlsBackground.setScale(targetSize.x / _controlsBackground.getLocalBounds().width, targetSize.y / _controlsBackground.getLocalBounds().height);

    
    _back.setTexture(this->_data->assets.GetTexture("Back"));

    _controlsBackground.setPosition(0, 0);
    _back.setPosition(0, 0);


}

void ControlsState::HandleInput()
{
    sf::Event event;

    while (this->_data->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            this->_data->window.close();
        }

        if (this->_data->input.IsSpriteClicked(this->_back, sf::Mouse::Left, this->_data->window))
        {
            // Switch To Menu
            this->_data->machine.AddState(StateRef(new ControlsState(_data)), false);
            this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
        }
    }
}

void ControlsState::Draw()
{
    
    this->_data->window.clear(sf::Color::Red);
    this->_data->window.draw(this->_controlsBackground);
    this->_data->window.draw(this->_back);

    sf::View ControlsMenuView;
	ControlsMenuView.reset(sf::FloatRect(0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT));
    this->_data->window.setView(ControlsMenuView);


    this->_data->window.display();
}