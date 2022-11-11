#include "Agua.h"

Agua::Agua(sf::Vector2f pos, sf::Vector2f tam, int d, float dC, bool dan, bool l) :
	Obstaculo(pos, tam, d, dC, dan, l)
{
	textura.loadFromFile("C:/Users/genti/Downloads/agua.png");
	sprite.setTexture(textura);
	body.setSize(sf::Vector2f(50, 50));;
	sprite.setScale(sf::Vector2f(1.5, 1.5));
	body.setPosition(400, 150);
	sprite.setPosition(400, 150);
}

Agua::~Agua() {}

void Agua::executar() {
	window->draw(sprite);
}