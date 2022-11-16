#include"jogador.h"

Jogador::Jogador(sf::Vector2f pos):
Personagem::Personagem(pos)
{
	vida = 10;
	body.setSize(size);
	body.setScale(2,2);
	sprite.setScale(2, 2);
	setPosition(pos);
}

Jogador::~Jogador() {}
