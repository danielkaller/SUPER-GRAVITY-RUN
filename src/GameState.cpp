//#include <sstream>
#include "../include/GameState.hpp"
#include <iostream>
#include <fstream>

//using std::cout;
//using std::endl;

GameState::GameState(GameDataRef data, string level) : _data(data)
{
	//Skapa alla object
	levelFile = level;
}

void GameState::Map(string filename) 
{
	char object;
	float x{0}; // int
	float y{0}; // int 
	//int line{0}; // int
	string word;   
	std::fstream file(filename);
	while(file>>word)
	{
		x = 0;
		for(long unsigned int i=0; i<word.length(); ++i)
		{
			object = word.at(i);
			if(object == 'B')
			{
				vecObjects.push_back(new Block{_data, x, y, "Block"});
			}

			else if(object == 'b')
			{
				vecObjects.push_back(new Block{_data, x, y, "Block", true});
			}
			
			else if(object == 'S')
			{
				vecObjects.push_back(new Spike{_data, x, y+51, "Spike"});
			}

			else if(object == 's')
			{
				vecObjects.push_back(new Spike{_data, x, y, "Spike", true});
			}

			else if(object == 'G')
			{
				g1 = new Spaceship(_data, x, y-235, "Spaceship");
			}
			
			else if(object == 'P')
			{ 
				p1 = new Player(_data, x, y, "DAN-mid");
			}
			else if(object == 'E')
			{	
				vecEnemies1.push_back(new Enemy1{_data, x, y, "Enemy1"});
			}
			x += SCREEN_HEIGHT / 10;
		}
		y += 960 / 10;
	}
}

void GameState::Init()
{
	string backgroundFile;
	string mapFile;
	string blockFile;
	string upsideDownBlockFile;
	if(levelFile == "level1")
	{
		backgroundFile = LEVEL1_BACKGROUND_FILEPATH;
		mapFile = LEVEL1_MAP_FILEPATH; 
		blockFile = NORMAL_BLOCK_FILEPATH; // LEVEL1_BLOCK_FILEPATH
		upsideDownBlockFile = UPSIDE_DOWN_NORMAL_BLOCK_FILEPATH;
	}
	else if(levelFile == "level2")
	{
		backgroundFile = LEVEL2_BACKGROUND_FILEPATH;
		mapFile = LEVEL2_MAP_FILEPATH; 
		blockFile = NORMAL_BLOCK_FILEPATH; // LEVEL2_BLOCK_FILEPATH
		upsideDownBlockFile = UPSIDE_DOWN_NORMAL_BLOCK_FILEPATH;
	}
	else if(levelFile == "level3")
	{
		backgroundFile = LEVEL3_BACKGROUND_FILEPATH;
		mapFile = LEVEL3_MAP_FILEPATH; 
		blockFile = ICE_BLOCK_FILEPATH; // LEVEL3_BLOCK_FILEPATH
		upsideDownBlockFile = UPSIDE_DOWN_ICE_BLOCK_FILEPATH;
	}
	//Gamebackground texture
	this->_data->assets.LoadTexture("Game Background", backgroundFile);
	_gameBackground.setTexture(this->_data->assets.GetTexture("Game Background"));

	sf::Vector2f targetSize(SCREEN_WIDTH + 3, SCREEN_HEIGHT + SCREEN_HEIGHT/3); 
	this->_gameBackground.setScale(targetSize.x / _gameBackground.getLocalBounds().width, targetSize.y / _gameBackground.getLocalBounds().height);

	//second Game background
	this->_data->assets.LoadTexture("Game Background2", backgroundFile);
	_gameBackground2.setTexture(this->_data->assets.GetTexture("Game Background2"));

	this->_gameBackground2.setScale(targetSize.x / _gameBackground2.getLocalBounds().width, targetSize.y / _gameBackground2.getLocalBounds().height);

	
	//Player textures
	this->_data->assets.LoadTexture("Player right", PLAYER_RIGHT_FILEPATH);
	this->_data->assets.LoadTexture("Player left", PLAYER_LEFT_FILEPATH);
	this->_data->assets.LoadTexture("Player right roof", PLAYER_RIGHT_ROOF_FILEPATH);
	this->_data->assets.LoadTexture("Player left roof", PLAYER_LEFT_ROOF_FILEPATH);

	//Enemy textures
	this->_data->assets.LoadTexture("Enemy1", ENEMY1_FILEPATH);

	//Block texture
	this->_data->assets.LoadTexture("Block", blockFile);
	this->_data->assets.LoadTexture("Upside Down Block", upsideDownBlockFile);
	this->_data->assets.LoadTexture("Spaceship", Spaceship_FILEPATH);
	this->_data->assets.LoadTexture("Spike", SPIKE_FILEPATH);
	this->_data->assets.LoadTexture("Upside Down Spike", UPSIDE_DOWN_SPIKE_FILEPATH);
	

	//MAP
	Map(mapFile);

}

void GameState::HandleInput()
{
	sf::Event event;

	while (this->_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->_data->window.close();
		}

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{


				delete g1;
				g1 = nullptr;

				delete p1;
				p1 = nullptr;

				vector<Object*> vecDeleteObjects;
				vecObjects.swap(vecDeleteObjects);
				vecObjects.clear();
				deleteObjects(vecDeleteObjects);
				vecDeleteObjects.clear();

				vector<Enemy1*> vecDeleteEnemies1;
				vecEnemies1.swap(vecDeleteEnemies1);
				vecEnemies1.clear();
				deleteObjects(vecDeleteEnemies1);
				vecDeleteEnemies1.clear();

				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
				//return;
			}
		}
			
	}
}

void GameState::Update(float dt)
{
	if(!(p1 == nullptr))
	{
		p1->update(vecObjects, vecEnemies1, this->_clock.getElapsedTime().asSeconds());

		float pos_g1 = g1->getPosx();
		float pos_p1 = p1->getPosx();

		for(auto it : vecEnemies1)
		{
			it->update(vecObjects, p1->getPosx());
		}

		if(p1->is_alive == false)
		{
			delete g1;
			g1 = nullptr;

			delete p1;
			p1 = nullptr;
	
			vector<Object*> vecDeleteObjects;
			vecObjects.swap(vecDeleteObjects);
			vecObjects.clear();
			deleteObjects(vecDeleteObjects);
			vecDeleteObjects.clear();

			vector<Enemy1*> vecDeleteEnemies1;
			vecEnemies1.swap(vecDeleteEnemies1);
			vecEnemies1.clear();
			deleteObjects(vecDeleteEnemies1);
			vecDeleteEnemies1.clear();

			this->_data->machine.AddState(StateRef(new GameOverState(_data, levelFile)), true);
		}
		
		if(pos_p1 >= pos_g1)
		{
			delete g1;
			g1 = nullptr;

			delete p1;
			p1 = nullptr;

			vector<Object*> vecDeleteObjects;
			vecObjects.swap(vecDeleteObjects);
			vecObjects.clear();
			deleteObjects(vecDeleteObjects);
			vecDeleteObjects.clear();
			
			vector<Enemy1*> vecDeleteEnemies1;
			vecEnemies1.swap(vecDeleteEnemies1);
			vecEnemies1.clear();
			deleteObjects(vecDeleteEnemies1);
			vecDeleteEnemies1.clear();

			float time = this->_clock.getElapsedTime().asSeconds();
			this->_data->machine.AddState(StateRef(new WinState(_data, levelFile, time)), true);
		}
	}
	dt = dt;

}


void GameState::Draw()
{
	this->_data->window.clear(sf::Color::White);

	if(!(p1 == nullptr))
	{
		if (p1->getPosx() >= x2 + _gameBackground.getLocalBounds().width/2)
		{
			x = x2 + _gameBackground.getLocalBounds().width	;
		} 

		if (p1->getPosx() >= x + _gameBackground.getLocalBounds().width/2) 
		{
			x2 = x + _gameBackground.getLocalBounds().width;
		}

		if (p1->getPosx() <= x2 + _gameBackground.getLocalBounds().width/2 && p1->getPosx() >= 0)
		{
			x = x2 - _gameBackground.getLocalBounds().width;
		} 

		if (p1->getPosx() <= x + _gameBackground.getLocalBounds().width/2 && p1->getPosx() >= 0) 
		{
			x2 = x - _gameBackground.getLocalBounds().width;
		}

		this->_data->window.draw(_gameBackground);
		_gameBackground.setPosition(x, 0);

		this->_data->window.draw(_gameBackground2);
		_gameBackground2.setPosition(x2, 0);

		sf::Sprite player = p1->getSprite();
		
		sf::View view;
		view.setCenter(player.getPosition().x, SCREEN_HEIGHT/2 + SCREEN_HEIGHT/10);
		this->_data->window.setView(view);

		p1->draw();
	}

	if(!(g1 == nullptr))
	{
		g1->draw();
	}
	for(Object* o1 : vecObjects)
	{
		if(o1->getName() == "Block")
		{
			b1 = new Block{_data, o1->getPosx(), o1->getPosy(), "Block", o1->getOnRoof()};
			b1->draw();
			delete b1;
		}
		else if(o1->getName() == "Spike")
		{
			s1 = new Spike{_data, o1->getPosx(), o1->getPosy(), "Spike", o1->getOnRoof()};
			s1->draw();
			delete s1;
		}
	}
	for(Enemy1* e1 : vecEnemies1)
	{
		e1->draw();
	}
	this->_data->window.display();
}

template<class T>
void GameState::deleteObjects(std::vector<T> & game_objects)
{
	for(auto& it : game_objects)
	{
		delete it;
    	it = nullptr;
	}
}
