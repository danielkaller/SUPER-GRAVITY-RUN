//#include <sstream>
#include "../include/GameOverState.hpp"


#include <string>

using std::string;

GameOverState::GameOverState(GameDataRef data, string level) : _data(data)
{
    levelFile = level;
}

void GameOverState::Init()
{
    this->_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
    this->_data->assets.LoadTexture("Return", RETURN_FILEPATH);
    this->_data->assets.LoadTexture("Try again", TRY_AGAIN_FILEPATH);

    _gameOverBackground.setTexture(this->_data->assets.GetTexture("Game Over Background"));

    sf::Vector2f targetSize(SCREEN_WIDTH, SCREEN_HEIGHT); 
	this->_gameOverBackground.setScale(targetSize.x / _gameOverBackground.getLocalBounds().width, targetSize.y / _gameOverBackground.getLocalBounds().height);

    
    _return.setTexture(this->_data->assets.GetTexture("Return"));
    _tryAgain.setTexture(this->_data->assets.GetTexture("Try again"));
    

    _gameOverBackground.setPosition(0, 0);
    _return.setPosition(0, SCREEN_HEIGHT - _return.getLocalBounds().height );
    _tryAgain.setPosition(SCREEN_WIDTH -  _tryAgain.getLocalBounds().width , SCREEN_HEIGHT - _tryAgain.getLocalBounds().height);

}

void GameOverState::HandleInput()
{
    sf::Event event;

    while (this->_data->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            this->_data->window.close();
        }

        if (this->_data->input.IsSpriteClicked(this->_return, sf::Mouse::Left, this->_data->window))
        {
            // Switch To Menu
            this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
        }

        if (this->_data->input.IsSpriteClicked(this->_tryAgain, sf::Mouse::Left, this->_data->window))
        {
            // Restart Game
            this->_data->machine.AddState(StateRef(new GameState(_data, levelFile)), true);
        }
        

    }
}



void GameOverState::Draw()
{
    
    this->_data->window.clear(sf::Color::Red);
    this->_data->window.draw(this->_gameOverBackground);
    this->_data->window.draw(this->_return);
    this->_data->window.draw(this->_tryAgain);

    sf::View GameOVerView;
	GameOVerView.reset(sf::FloatRect(0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT));
    this->_data->window.setView(GameOVerView);


    this->_data->window.display();
}