#include "Espinho.h"

Espinho::Espinho(sf::Vector2f position, sf::Vector2f size, int d, float dC, bool dan, bool l) :
	Obstaculos::Obstaculo(position, size, d, dC, dan, l)
{
	textura.loadFromFile("C:/Users/genti/Downloads/espinho.png");
	sprite.setTexture(textura);
	sprite.setScale(sf::Vector2f(2,2));
	body.setSize(sf::Vector2f(10, 10));
	body.setPosition(300, 103);
	sprite.setPosition(300, 103);

//	sprite.move(position);
}

Espinho::~Espinho() {}

void Espinho::executar() {
	window->draw(sprite);
}