#include "Game.h"

#ifndef MAINMENU_H
#define MAINMENU_H

#include <list>
class MainMenu
{
public:
	enum MenuResult{Nothing, Play, Exit};
	struct MenuItem
	{
		sf::Rect<int> rect;
		MenuResult action;
	};

	MenuResult Show(sf::RenderWindow& sumWindow);
private:
	MenuResult GetMenuResponse(sf::RenderWindow& sumWindow);
	MenuResult HandleClick(int x, int y);
	std::list<MenuItem> _menuItems;	
};
#endif