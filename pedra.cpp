#include "pedra.h"

Pedra::Pedra(sf::Vector2f pos) :
	Obstaculo(pos)
{
	id = pedra;
	setSprite("Assets/pedra.png");
	setPosicao(pos);
	body.setSize(sf::Vector2f(160, 180));
	setEscala(sf::Vector2f(4, 2));
}

Pedra::~Pedra() {}

void Pedra::executar() {
	renderizar();
	atualizar();
}