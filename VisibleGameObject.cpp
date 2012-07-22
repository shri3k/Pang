#include "VisibleGameObject.h"
VisibleGameObject::VisibleGameObject()
{
	_isLoaded = false;
}
VisibleGameObject::VisibleGameObject()
{
}
void VisibleGameObject::Load(std::string filename)
{
	if(!_image.loadFromFile(filename))
	{
		_filename = "";
		_isLoaded = false;
	}
	else
	{
		_filename = filename;
		_sprite.setTexture(_image);
		_isLoaded = true;
	}
}

void VisibleGameObject::Draw(sf::RenderWindow & renderwindow)
{
	if(_isLoaded)
	{
		renderwindow.draw(_sprite);
	}
}

void VisibleGameObject::SetPosition(float xpos, float ypos)
{
	if(_isLoaded)
	{
		_sprite.setPosition(xpos,ypos);
	}
}
