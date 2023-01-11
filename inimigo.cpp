#include "inimigo.h"
#include "jogador.h"
#include <iostream>
using std::cout;
using std::endl;

Inimigo::Inimigo(Math::CoordF pos, Jogador* p1, Jogador* p2):
	Personagem(pos)
{
	podeAtacar = true;
	pJ1 = p1;
	pJ2 = p2;
	timerCooldown = 0;
	visao = 0;
}

Inimigo::~Inimigo() {}

void Inimigo::setVisao(float v) {
	visao = v;
}

float Inimigo::getVisao() {
	return visao;
}

bool Inimigo::getPersegue(Jogador* pJ) {
	if (fabs(distanciaPersonagens(pJ)) <= getVisao() && !pJ->morreu())
		return true;
	return false;
}

Jogador* Inimigo::definePerseguido(Jogador* pJ1, Jogador* pJ2) {
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
		velocidade.x = -vmax.x;
	else
		velocidade.x = vmax.x;
	setPosicao(posicao);
}

void Inimigo::atacado(Jogador* pJ) {
	if (pJ->getAtacando() && distanciaPersonagens(pJ) < pJ->getAlcance()) {
		tomaDano(pJ->getDano());
	}
}

void Inimigo::hostilizar() {
	if (getPersegue(pJ1) || getPersegue(pJ2)) {
		perseguicao(definePerseguido(pJ1, pJ2));
		ataca(definePerseguido(pJ1, pJ2));
	}
	atacado(pJ1);
	atacado(pJ2);
}