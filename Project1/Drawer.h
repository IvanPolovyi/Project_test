#pragma once



class Drawer: public sf::Drawable
{
	Drawer();
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states, sf::Sprite sprite) const;
	
};
