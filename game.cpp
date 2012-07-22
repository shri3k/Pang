#include "Game.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include <iostream>

void Game::Start(void)
{
	if(_gameState != Uninitialized)
		return;
	
	_gameState = Game::ShowingSplash;
	arena.create(sf::VideoMode(1024,768,32),"Frameworks");
//	sf::ContextSettings settings = arena.getSettings();
//	std::cout << settings.majorVersion << "." << settings.minorVersion << std::endl;
	while(!IsExiting())
	{
		GameLoop();
	}
	arena.close();
}

bool Game::IsExiting(void)
{
	if(_gameState == Game::Exiting)
		return true;
	else
		return false;
}

void Game::GameLoop(void)
{
	switch(_gameState)
	{
	case Game::Playing:
		{
			sf::Event myEvent;
			while(arena.pollEvent(myEvent))
			{
				arena.clear(sf::Color(sf::Color::Yellow));
				arena.display();

				if(myEvent.type == sf::Event::Closed)
					_gameState = Game::Exiting;
				if(myEvent.type == sf::Event::KeyPressed)
				{
					if(myEvent.key.code == sf::Keyboard::Escape)
						ShowMenu();
				}
			}
			break;
		}

		case Game::ShowingSplash:
			{
				ShowSplashScreen();
				break;
			}
		case Game::ShowingMenu:
			{
				ShowMenu();
				break;
			}
	}
}

void Game::ShowSplashScreen()
{
	SplashScreen splash;
	splash.Show(arena);
	_gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
	MainMenu menu;
	MainMenu::MenuResult result = menu.Show(arena);
	switch(result)
	{
	case MainMenu::Exit:
		_gameState = Game::Exiting;
		break;
	case MainMenu::Play:
		_gameState = Game::Playing;
		break;
	}
}

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::arena;