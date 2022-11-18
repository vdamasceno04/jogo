#include "Plataforma.h"

Plataforma::Plataforma(sf::Vector2f pos) :
	Obstaculo(pos)
{
	id = plataforma;
	setSprite("C:/Users/genti/Downloads/texturas/chao2.png");
	setPosicao(pos);
	body.setSize(sf::Vector2f(67, 69));
	setEscala(sf::Vector2f(2, 2));
}

Plataforma::~Plataforma() {}

void Plataforma::executar() {
	renderizar();
}