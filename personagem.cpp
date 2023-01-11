#include "personagem.h"

Personagem::Personagem(Math::CoordF pos):
Entidade::Entidade(pos) {
	atacando = false;
	podeAtacar = true;
	olhaDireita = true;
	alcance = 0;
	duracaoCooldown = 0;
	timerCooldown = 0;
	setPosicao(pos);
}

Personagem::~Personagem(){}

void Personagem::setVida(int v) { vida = v; }

int Personagem::getVida() { return vida; }


bool Personagem::morreu() {
	if (vida <= 0) {
		return true;
	}
	return false;
}

void Personagem::setOlhar(bool direita) {
	if (direita)
		olhaDireita = true;
	else
		olhaDireita = false;
}

bool Personagem::getOlharDireita() {
	return olhaDireita;
}

void Personagem::contaTempoAtaque(const float dt) {
	if (atacando) {
		timerCooldown = 0;
		atacando = false;
	}
	else 
		timerCooldown += dt;
}

float Personagem::distanciaPersonagens(Personagem* pP) { return fabs(body.getPosition().x - pP->getBody().getPosition().x); }

void Personagem::atualizapodeAtacar()
{
	if (duracaoCooldown <= timerCooldown )
		podeAtacar = true;
	else
		podeAtacar = false;
}

bool Personagem::acertaAtaque(Personagem* p) {
	if (distanciaPersonagens(p) <= alcance)
		return true;
	return false;
}

bool Personagem::getAtacando() { return atacando; }


void Personagem::remover() {
	if (morreu())
		remove = true;
}

float Personagem::getAlcance() { return alcance; }

void Personagem::golpear(Personagem* p) {
	if (podeAtacar) {
		p->tomaDano(dano);
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