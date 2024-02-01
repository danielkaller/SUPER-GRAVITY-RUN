#include <sstream>
#include "../include/LevelSelectorState.hpp"


LevelSelectorState::LevelSelectorState(GameDataRef data) : _data(data)
{

}

void LevelSelectorState::Init()
{
    this->_data->assets.LoadTexture("Level Selector Background", LEVEL_SELECTOR_BACKGROUND_FILEPATH );
    this->_data->assets.LoadTexture("Level Selector", LEVEL_SELECTOR_FILEPATH);
    this->_data->assets.LoadTexture("Level1", LEVEL1_BACKGROUND_FILEPATH); //
    this->_data->assets.LoadTexture("Level2", LEVEL2_BACKGROUND_FILEPATH); //
    this->_data->assets.LoadTexture("Level3", LEVEL3_BACKGROUND_FILEPATH); //
    this->_data->assets.LoadTexture("Back", BACK_FILEPATH);

    _levelBackground.setTexture(this->_data->assets.GetTexture("Level Selector Background"));
    sf::Vector2f targetSize(SCREEN_WIDTH, SCREEN_HEIGHT); 
	this->_levelBackground.setScale(targetSize.x / _levelBackground.getLocalBounds().width, targetSize.y / _levelBackground.getLocalBounds().height);
    
    
    
    _levelSelector.setTexture(this->_data->assets.GetTexture("Level Selector"));
    _level1.setTexture(this->_data->assets.GetTexture("Level1")); //
    _level2.setTexture(this->_data->assets.GetTexture("Level2")); //
    _level3.setTexture(this->_data->assets.GetTexture("Level3")); //
    _back.setTexture(this->_data->assets.GetTexture("Back"));

    

    this->_level1.setScale(0.2,0.2);
    _level1.setPosition(((SCREEN_WIDTH - (_level1.getGlobalBounds().width * 3)) / 4) , (SCREEN_HEIGHT / 3) - (_level1.getGlobalBounds().height / 2));

    this->_level2.setScale(0.2,0.2);                                     
    _level2.setPosition(((SCREEN_WIDTH - (_level1.getGlobalBounds().width * 3)) / 4) * 2 + _level1.getGlobalBounds().width , (SCREEN_HEIGHT / 3) - (_level1.getGlobalBounds().height / 2));

    this->_level3.setScale(0.2,0.2);
    _level3.setPosition(((SCREEN_WIDTH - (_level1.getGlobalBounds().width * 3)) / 4) * 3 + _level1.getGlobalBounds().width *2 , (SCREEN_HEIGHT / 3) - (_level1.getGlobalBounds().height / 2));

    
    _levelSelector.setPosition((SCREEN_WIDTH / 2) - (_levelSelector.getGlobalBounds().width / 2), (0 + (_levelSelector.getGlobalBounds().height * 0.5)));
    _levelBackground.setPosition(0, 0);
    _back.setPosition(0, 0);
    
}

void LevelSelectorState::HandleInput()
{
    sf::Event event;

    while (this->_data->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            this->_data->window.close();
        }

        if (this->_data->input.IsSpriteClicked(this->_level1, sf::Mouse::Left, this->_data->window))
        {
            // Switch To Level 1
            this->_data->machine.AddState(StateRef(new GameState(_data, "level1")), true);
        }

        if (this->_data->input.IsSpriteClicked(this->_level2, sf::Mouse::Left, this->_data->window))
        {
            // Switch To Level 2
            this->_data->machine.AddState(StateRef(new GameState(_data, "level2")), true);
            
        }

        if (this->_data->input.IsSpriteClicked(this->_level3, sf::Mouse::Left, this->_data->window))
        {
            // Switch To Level 2
            this->_data->machine.AddState(StateRef(new GameState(_data, "level3")), true);
            
        }

        if (this->_data->input.IsSpriteClicked(this->_back, sf::Mouse::Left, this->_data->window))
        {
            // Switch To Menu
            this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
        }


    }
}

void LevelSelectorState::Draw()
{
    //this->_data->window.clear(sf::Color::Red);
    
    
    this->_data->window.draw(this->_levelBackground);
    this->_data->window.draw(this->_levelSelector);
    this->_data->window.draw(this->_back);
    this->_data->window.draw(this->_level1); //
    this->_data->window.draw(this->_level2); //
    this->_data->window.draw(this->_level3); //
    

    sf::View LevelSelectorView;
	LevelSelectorView.reset(sf::FloatRect(0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT));
	this->_data->window.setView(LevelSelectorView);

    this->_data->window.display();
}