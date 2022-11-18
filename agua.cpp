#include "Agua.h"

Agua::Agua(sf::Vector2f pos) :
	Obstaculo(pos)
{
	id = agua;
	lentidao = 0.3;
	body.setSize(sf::Vector2f(63, 37));
	setSprite("C:/Users/genti/Downloads/texturas/agua.png");
	setPosicao(pos);
	setEscala(sf::Vector2f(2, 4));
}

Agua::~Agua() {}

void Agua::executar() {
	renderizar();
}