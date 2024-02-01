LIBS := -lsfml-system -lsfml-graphics -lsfml-window



all: main.o InputManager.o AssetManager.o stateMachine.o Game.o SplashState.o MainMenuState.o GameState.o ControlsState.o GameOverState.o WinState.o  LevelSelectorState.o player.o entity.o object.o block.o Enemy1.o spike.o spaceship.o
	g++ main.o InputManager.o AssetManager.o stateMachine.o Game.o SplashState.o MainMenuState.o GameState.o ControlsState.o GameOverState.o WinState.o LevelSelectorState.o player.o entity.o object.o block.o Enemy1.o spike.o spaceship.o -o game $(LIBS)

main.o: src/main.cpp
	g++ -c src/main.cpp

Game.o: src/Game.cpp
	g++ -c src/Game.cpp
	
InputManager.o: src/InputManager.cpp
	g++ -c src/InputManager.cpp 
	
AssetManager.o: src/AssetManager.cpp
	g++ -c src/AssetManager.cpp

stateMachine.o: src/stateMachine.cpp
	g++ -c src/stateMachine.cpp

SplashState.o: src/SplashState.cpp
	g++ -c src/SplashState.cpp

MainMenuState.o: src/MainMenuState.cpp
	g++ -c src/MainMenuState.cpp

GameState.o: src/GameState.cpp
	g++ -c src/GameState.cpp

ControlsState.o: src/ControlsState.cpp
	g++ -c src/ControlsState.cpp

GameOverState.o: src/GameOverState.cpp
	g++ -c src/GameOverState.cpp
	
LevelSelectorState.o: src/LevelSelectorState.cpp
	g++ -c src/LevelSelectorState.cpp

WinState.o: src/WinState.cpp
	g++ -c src/WinState.cpp



spike.o: src/spike.cpp
	g++ -c src/spike.cpp

player.o: src/player.cpp
	g++ -c src/player.cpp
	
entity.o: src/entity.cpp
	g++ -c src/entity.cpp

object.o: src/object.cpp
	g++ -c src/object.cpp

block.o: src/block.cpp
	g++ -c src/block.cpp

Enemy1.o: src/Enemy1.cpp
	g++ -c src/Enemy1.cpp

spaceship.o: src/spaceship.cpp
	g++ -c src/spaceship.cpp

clean:
	rm *.o game