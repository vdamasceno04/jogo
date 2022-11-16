#include "Espinho.h"

Espinho::Espinho(sf::Vector2f pos, ID i) :
	Obstaculos::Obstaculo(pos, i)
{
	setSprite("C:/Users/genti/Downloads/texturas/espinho.png");
	body.setSize(sf::Vector2f(67, 28));
	setPosition(pos);
	body.setScale(2, 2);
	sprite.setScale(2, 2);
}

Espinho::~Espinho() {}

void Espinho::executar() {
	renderizar();
}