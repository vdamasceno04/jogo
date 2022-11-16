#include "Agua.h"

Agua::Agua(sf::Vector2f pos) :
	Obstaculo(pos)
{
	body.setSize(sf::Vector2f(63, 37));
	setSprite("C:/Users/genti/Downloads/texturas/agua.png");
	setPosition(pos);
	body.setScale(2, 4);
	sprite.setScale(2, 4);
}

Agua::~Agua() {}

void Agua::executar() {
	renderizar();
}