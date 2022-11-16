#include "Espinho.h"

Espinho::Espinho(sf::Vector2f pos, ID i) :
	Obstaculos::Obstaculo(pos, i)
{
	dano = 1;
	danificar = true;
	duracaoCooldown = 100;
	setSprite("C:/Users/genti/Downloads/texturas/espinho.png");
	body.setSize(sf::Vector2f(67, 28));
	setPosicao(pos);
	setEscala(sf::Vector2f(2, 2));
}

Espinho::~Espinho() {}

void Espinho::executar() {
	renderizar();
}