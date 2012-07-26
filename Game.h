//Todo:- Create data structure for gamestate
//       

#ifndef GAME_H
#define GAME_H
#include <SFML\Graphics.hpp>
#include <iostream>
#include "PlayerPaddle.h"
#include "GameObjectManager.h"

class Game
{
public:
	static void Start();
private:
	enum GameState{Uninitialized, ShowingSplash, Playing, ShowingMenu, Paused, Exiting};

	static bool IsExiting();
	static void GameLoop();

	static void ShowSplashScreen();
	static void ShowMenu();

	static GameState _gameState;
	static sf::RenderWindow arena;
	static GameObjectManager _gameObjectManager;
};

#endif // !GAME_H