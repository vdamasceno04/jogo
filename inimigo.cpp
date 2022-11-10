#include "inimigo.h"


Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, int v, int d, float dC, float dA, float vR) :
	Personagem(pos, tam, v, d, dC, dA)
{
	setPosition(pos);
	textura.loadFromFile("C:/Users/genti/Downloads/Legacy-Fantasy-VL.1 - High Forest - Update 1.9/Mob/Snail/all.png");
	sprite.setTexture(textura);
	body.setSize(sf::Vector2f(50, 50));
	viewRange = vR;
}

Inimigo::~Inimigo() {}

void Inimigo::setViewRange(float vR) {
	viewRange = vR;
}

float Inimigo::getViewRange() {
	return viewRange;
}