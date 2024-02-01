//#include <sstream>
//#include <fstream>
#include "../include/WinState.hpp"
#include "../include/GameState.hpp"
#include "../include/Definitions.hpp"
#include "../include/MainMenuState.hpp"

#include <map>

#include <string>
#include <iostream>

using std::string;

WinState::WinState(GameDataRef data, string level, float time) : _data(data)
{
    levelFile = level; 
    timeElapsed = time;
    
}

void WinState::Init()
{
    this->_data->assets.LoadTexture("Game Won Background", GAME_WON_BACKGROUND_FILEPATH);
    this->_data->assets.LoadTexture("Return", RETURN_WIN_FILEPATH);
    this->_data->assets.LoadTexture("Play again", PLAY_AGAIN_FILEPATH);
    this->_data->assets.LoadTexture("Time", TIME_FILEPATH);


    _gameOverBackground.setTexture(this->_data->assets.GetTexture("Game Won Background"));

    sf::Vector2f targetSize(SCREEN_WIDTH, SCREEN_HEIGHT); 
	this->_gameOverBackground.setScale(targetSize.x / _gameOverBackground.getLocalBounds().width, targetSize.y / _gameOverBackground.getLocalBounds().height);

    _time.setTexture(this->_data->assets.GetTexture("Time"));
    _return.setTexture(this->_data->assets.GetTexture("Return"));
    _playAgain.setTexture(this->_data->assets.GetTexture("Play again"));
    

    _gameOverBackground.setPosition(0, 0);
    _time.setPosition(SCREEN_WIDTH / 2 - (_time.getLocalBounds().width / 2) , SCREEN_HEIGHT / 2);
    _return.setPosition(0, SCREEN_HEIGHT - _return.getLocalBounds().height );
    _playAgain.setPosition(SCREEN_WIDTH -  _playAgain.getLocalBounds().width , SCREEN_HEIGHT - _playAgain.getLocalBounds().height);

    if ( !font.loadFromFile( "Resources/fonts/Sanseriff.ttf" ) )
    {
        std::cout << "Error loading" << std::endl;
    }
    
    std::string stringTimeElapsed = std::to_string(timeElapsed);

    _text.setFont( font );
    _text.setString(stringTimeElapsed); // gö till string
    _text.setCharacterSize( 70 );
    _text.setFillColor( sf::Color(0, 227, 237) );
    _text.setPosition(SCREEN_WIDTH / 2 - (_text.getGlobalBounds().width / 2 ) , SCREEN_HEIGHT / 2 + _time.getLocalBounds().height); 


}

void WinState::HandleInput()
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

        if (this->_data->input.IsSpriteClicked(this->_playAgain, sf::Mouse::Left, this->_data->window))
        {
            // Restart Game
            this->_data->machine.AddState(StateRef(new GameState(_data, levelFile)), true);
        }
        

    }
}

/*
void WinState::Record()
{

    öppna mappen
    läs och hitta rätt bana 
    kolla om rekord tiden är lägre än den nya tiden
    om den är lägre byt ut den nuvarande tiden
    spara mappen
    
    std::cout << "wooo" << std::endl;
    std::fstream data_file;
    std::string data;
    data_file.open("Resources/levels/record.txt",std::ios::out);
    while(getline(data_file,data))
    {
        std::cout << "Hej" << data << std::endl;
    }



}
 */

void WinState::Draw()
{
    this->_data->window.clear(sf::Color::Red);
    this->_data->window.draw(this->_gameOverBackground);
    this->_data->window.draw(this->_return);
    this->_data->window.draw(this->_playAgain);
    this->_data->window.draw(this->_time);
    this->_data->window.draw(this->_text);
    


    sf::View GameOVerView;
	GameOVerView.reset(sf::FloatRect(0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT));
    this->_data->window.setView(GameOVerView);


    this->_data->window.display();
}