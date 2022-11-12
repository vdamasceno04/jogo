#include "Agua.h"

Agua::Agua(sf::Vector2f pos, sf::Vector2f tam, int d, float dC, bool dan, bool l) :
	Obstaculo(pos, tam, d, dC, dan, l)
{
	body.setSize(size);
	textura.loadFromFile("C:/Users/genti/Downloads/agua.png");
	sprite.setTexture(textura);
	sprite.move(position);
	body.setScale(2, 4);
	sprite.setScale(2, 4);
}

Agua::~Agua() {}

void Agua::executar() {
	window->draw(sprite);
}