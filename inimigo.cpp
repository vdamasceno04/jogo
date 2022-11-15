#include "inimigo.h"
#include "jogador.h"
#include <iostream>
using std::cout;
using std::endl;

Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, int v, int d, float dC, float alc, float dA, float vR, Jogador* p1, Jogador* p2):
	Personagem(pos, tam, v, d, alc, dC, dA), pJ1(p1), pJ2(p2)
{
	body.setPosition(pos);
	textura.loadFromFile("C:/Users/genti/Downloads/Legacy-Fantasy-VL.1 - High Forest - Update 1.9/Mob/Snail/all.png");
	sprite.setTexture(textura);
	body.setSize(sf::Vector2f(50, 50));
	viewRange = vR;
	clock.restart();
}

Inimigo::~Inimigo() {}

void Inimigo::setViewRange(float vR) {
	viewRange = vR;
}

float Inimigo::getViewRange() {
	return viewRange;
}

//void Inimigo::setpJogador(Jogador* p) { pJ = p; }

bool Inimigo::getPersegue(Jogador* pJ) {
	if (fabs(distanciaPersonagens(pJ)) <= getViewRange() && !pJ->morreu())
		return true;
	return false;
}

Jogador* Inimigo::setPerseguido(Jogador* pJ1, Jogador* pJ2) {
	if (getPersegue(pJ1) && !getPersegue(pJ2))
		return pJ1;
	else if (!getPersegue(pJ1) && getPersegue(pJ2))
		return pJ2;
	else
		if (distanciaPersonagens(pJ1) <= distanciaPersonagens(pJ2))
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

void Inimigo::ataca(Jogador* pJ) {
	atualizapodeAtacar();
	if (acertaAtaque(pJ) && getPersegue(pJ)) {
		if (podeAtacar) {
			pJ->tomaDano(dano);
			atacando = true;
			clock.restart();
			contaTempoAtaque(clock.getElapsedTime().asSeconds());
		}
		else
			timerCooldown += clock.getElapsedTime().asSeconds();
	}

//	cout << "vida: " << pJ->getVida() << endl;
}