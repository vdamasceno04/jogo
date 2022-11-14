#include "inimigo.h"
#include "jogador.h"
#include <iostream>
using std::cout;
using std::endl;

Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, int v, int d, float dC, float dA, float vR, bool p, Jogador* pJ):
	Personagem(pos, tam, v, d, dC, dA), pJogador(pJ)
{
	body.setPosition(pos);
	textura.loadFromFile("C:/Users/genti/Downloads/Legacy-Fantasy-VL.1 - High Forest - Update 1.9/Mob/Snail/all.png");
	sprite.setTexture(textura);
	body.setSize(sf::Vector2f(50, 50));
	persegue = p;
	viewRange = vR;
}

Inimigo::~Inimigo() {}

void Inimigo::setViewRange(float vR) {
	viewRange = vR;
}

float Inimigo::getViewRange() {
	return viewRange;
}

float Inimigo::distanciaJogador(Jogador* pJ) { return body.getPosition().x - pJogador->getBody().getPosition().x; }

void Inimigo::setpJogador(Jogador* p) { pJogador = p; }

void Inimigo::setPerseguir() {
	if (fabs(distanciaJogador(pJogador)) <= getViewRange())
		persegue = true;
}

void Inimigo::perseguicao() {
	if (persegue) {
		if (pJogador->getBody().getPosition().x < body.getPosition().x)
			velocidade.x = fabs(velocidade.x) * -1;
		else
			velocidade.x = fabs(velocidade.x);
	position.x += velocidade.x;
	body.setPosition(position);
	sprite.setPosition(position);
	}
}