#include "inimigo.h"
#include "jogador.h"
#include <iostream>
using std::cout;
using std::endl;

Inimigo::Inimigo(sf::Vector2f pos, Jogador* p1, Jogador* p2):
	Personagem(pos)
{
	podeAtacar = true;
	pJ1 = p1;
	pJ2 = p2;
	setPosition(pos);
	textura.loadFromFile("C:/Users/genti/Downloads/Legacy-Fantasy-VL.1 - High Forest - Update 1.9/Mob/Snail/all.png");
	sprite.setTexture(textura);
	body.setSize(sf::Vector2f(50, 50));
	timerCooldown = 0;
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
	setPosition(position);
	sprite.setPosition(position);
}

void Inimigo::ataca(Jogador* pJ) {
	atualizapodeAtacar();
	if (acertaAtaque(pJ) && getPersegue(pJ)) {
		if (podeAtacar) {
			pJ->tomaDano(dano);
			podeAtacar = false;
			timerCooldown = 0;
			pGG->getClock().restart();
			timerCooldown += pGG->getClock().getElapsedTime().asSeconds();
		}
		else {
			pGG->getClock().restart();
			timerCooldown += pGG->getClock().getElapsedTime().asSeconds();
		}
	}
}

void Inimigo::hostilizar() {
	if (getPersegue(pJ1) || getPersegue(pJ2)) {
		perseguicao(setPerseguido(pJ1, pJ2));
		ataca(setPerseguido(pJ1, pJ2));
	}
	cout << "vida1 = " << pJ1->getVida() << endl;
	cout << "vida2 = " << pJ2->getVida() << endl;
}