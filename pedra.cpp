#include "pedra.h"

Pedra::Pedra(sf::Vector2f pos) :
	Obstaculo(pos)
{
	id = pedra;
	setSprite("Assets/pedra.png");
	setPosicao(pos);
	body.setSize(sf::Vector2f(80, 140));
	setEscala(sf::Vector2f(2, 1));
}

Pedra::~Pedra() {}

void Pedra::executar() {
	renderizar();
	atualizar();
}