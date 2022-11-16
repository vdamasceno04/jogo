#include"jogador.h"

Jogador::Jogador(sf::Vector2f pos, ID i):
Personagem::Personagem(pos, i)
{
	setVida(15);
	body.setSize(size);
	body.setScale(2,2);
	sprite.setScale(2, 2);
	setPosition(pos);
}

Jogador::~Jogador() {}
