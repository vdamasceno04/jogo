#include "Espinho.h"

Espinho::Espinho(sf::Vector2f position, sf::Vector2f size, int d, float dC, bool dan, bool l) :
	Obstaculos::Obstaculo(position, size, d, dC, dan, l)
{
	body.setSize(size);
	textura.loadFromFile("C:/Users/genti/Downloads/espinho.png");
	sprite.setTexture(textura);
	sprite.move(position);
	body.setScale(2, 2);
	sprite.setScale(2, 2);
}

Espinho::~Espinho() {}

void Espinho::executar() {
	window->draw(sprite);
}