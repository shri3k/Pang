//Todo:- Create data structure for gamestate
//       

#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>

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
};

#endif // !GAME_H