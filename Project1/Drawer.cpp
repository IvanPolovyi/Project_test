#include "SFML/Graphics.hpp"
#include "Drawer.h"

using namespace sf;
Drawer::Drawer() = default;

void Drawer::draw(sf::RenderTarget& target, sf::RenderStates states, sf::Sprite sprite) const
{
    target.draw(sprite, states);
    
}