#include"jogador.h"

Jogador::Jogador(sf::Vector2f pos, sf::Vector2f size, int v, int d, float alc, float dC, float dA):
Personagem::Personagem(pos, size, v, d, alc, dC, dA)
{
//	pGG->loadTexture("C:/Users/genti/Downloads/Legacy-Fantasy-VL.1 - High Forest - Update 1.9/Character/Idle/Idle.gif");
	textura.loadFromFile("C:/Users/genti/Downloads/Legacy-Fantasy-VL.1 - High Forest - Update 1.9/Character/Idle/Idle.gif");
	sprite.setTexture(textura);
	body.setSize(size);
	body.setScale(2,2);
	sprite.setScale(2, 2);
	body.setPosition(pos);
	sprite.setPosition(pos);
}

Jogador::~Jogador() {}
