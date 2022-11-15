#include "Plataforma.h"

Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam, int d, float dC, bool dan, bool l) :
	Obstaculo(pos, tam, d, dC, dan, l)
{
	textura.loadFromFile("C:/Users/genti/Downloads/texturas/chao2.png");
	sprite.setTexture(textura);
	body.setPosition(position);
	sprite.move(position);
	body.setScale(2, 2);
	sprite.setScale(2, 2);
}

Plataforma::~Plataforma() {}

void Plataforma::executar() {
	window->draw(sprite);
}