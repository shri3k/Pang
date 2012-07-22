#include "MainMenu.h"
MainMenu::MenuResult MainMenu::Show(sf::RenderWindow & window)
{
	sf::Texture menuImg;
	if(!menuImg.loadFromFile("bin/img/menu.png"))
		return Nothing;

	sf::Sprite menuSprite(menuImg);

	MenuItem playButton;
	playButton.rect.top = 145;
	playButton.rect.left = 0;
	playButton.rect.height = 235;
	playButton.rect.width = 1023;
	playButton.action = Play;

	MenuItem exitButton;
	exitButton.rect.top = 383;
	exitButton.rect.height = 177;
	exitButton.rect.left = 0;
	exitButton.rect.width = 1023;
	exitButton.action = Exit;

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);

	window.draw(menuSprite);
	window.display();

	return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow & window)
{
	sf::Event menuEvent;

	while(true)
	{
		while(window.pollEvent(menuEvent))
		{
			if(menuEvent.type ==  sf::Event::EventType::MouseButtonPressed)
				return HandleClick(menuEvent.mouseButton.x,menuEvent.mouseButton.y);
			if(menuEvent.type == sf::Event::Closed)
				return Exit;
		}
	}
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;

	for( it = _menuItems.begin(); it != _menuItems.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if(menuItemRect.top < y
			&& menuItemRect.left < x
			&& (y - menuItemRect.top) < menuItemRect.height
			&& (x - menuItemRect.left) < menuItemRect.width)
		{
			return (*it).action;
		}
	}
	return Nothing;
}