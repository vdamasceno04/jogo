#include "inimigo.h"
#include "jogador.h"
#include <iostream>
using std::cout;
using std::endl;

Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, int v, int d, float dC, float dA, float vR, Jogador* p1, Jogador* p2):
	Personagem(pos, tam, v, d, dC, dA), pJ1(p1), pJ2(p2)
{
	body.setPosition(pos);
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

float Inimigo::distanciaJogador(Jogador* pJ) { return body.getPosition().x - pJ->getBody().getPosition().x; }

//void Inimigo::setpJogador(Jogador* p) { pJ = p; }

bool Inimigo::setPersegue(Jogador* pJ) {
	if (fabs(distanciaJogador(pJ)) <= getViewRange())
		return true;
	return false;
}

Jogador* Inimigo::setPerseguido(Jogador* pJ1, Jogador* pJ2) {
	if (setPersegue(pJ1) && !setPersegue(pJ2))
		return pJ1;
	else if (!setPersegue(pJ1) && setPersegue(pJ2))
		return pJ2;
	else
		if (distanciaJogador(pJ1) >= distanciaJogador(pJ2))
			return pJ1;
	return pJ2;
}
void Inimigo::perseguicao(Jogador* pJ) {
	
	if (pJ->getBody().getPosition().x < body.getPosition().x)
		velocidade.x = fabs(velocidade.x) * -1;
	else
		velocidade.x = fabs(velocidade.x);
	position.x += velocidade.x;
	body.setPosition(position);
	sprite.setPosition(position);
}