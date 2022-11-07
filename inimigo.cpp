#include "inimigo.h"


Inimigo::Inimigo()
{
	body.setFillColor(sf::Color::Red);
	body.setPosition(sf::Vector2f(200.f, 200.f));
}

Inimigo::~Inimigo() {}