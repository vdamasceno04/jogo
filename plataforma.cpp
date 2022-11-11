#include "Plataforma.h"

Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam, int d, float dC, bool dan, bool l) :
	Obstaculo(pos, tam, d, dC, dan, l)
{
	textura.loadFromFile("C:/Users/genti/Downloads/chao.png");
	sprite.setTexture(textura);
	body.setSize(sf::Vector2f(50, 50));

	sprite.move(position);
}

Plataforma::~Plataforma() {}

void Plataforma::executar() {
	window->draw(sprite);
}