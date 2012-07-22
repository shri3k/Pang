#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow & sumWindow)
{
	sf::Texture myImage;
	if(!myImage.loadFromFile("bin/img/splash.jpg"))
		return;

	sf::Sprite mySprite(myImage);
	sumWindow.draw(mySprite);
	sumWindow.display();

	sf::Event myEvent2;
	while(true)
	{
		while(sumWindow.pollEvent(myEvent2))
			{
				if(myEvent2.type == sf::Event::EventType::KeyPressed 
				|| myEvent2.type == sf::Event::EventType::MouseButtonPressed
				|| myEvent2.type == sf::Event::EventType::Closed)
				{
					return;
				}
			}
	}
}