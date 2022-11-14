#include "personagem.h"

Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, int v, int d, float alc, float dC, float dA):
Entidade::Entidade(pos, tam) {
	vida = v;
	dano = d;
	alcance = alc;
	atacando = false;
	atacou = false;
	timerAtaque = 0;
	timerCooldown = 0;
	podeAtacar = true;
	duracaoCooldown = dC;
	duracaoAtaque = dA;
	olhaDireita = true;
	setPosition(pos);
	setSize(tam);
}

Personagem::~Personagem(){}

void Personagem::setVida(int v) { vida = v; }

int Personagem::getVida() { return vida; }

void Personagem::tomaDano(int ferimento) { vida -= ferimento;}

bool Personagem::morreu() {
	if (vida <= 0)
		return true;
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
		timerAtaque += dt;
		if (timerAtaque >= duracaoAtaque)
			atacando = false;
	}
	else {
		timerAtaque += dt;
		timerCooldown = 0;
	}
}

float Personagem::distanciaPersonagens(Personagem* pP) { return body.getPosition().x - pP->getBody().getPosition().x; }

void Personagem::atualizapodeAtacar()
{
	if (duracaoCooldown <= timerCooldown)
		podeAtacar = true;
}

bool Personagem::acertouAtaque(Personagem* p) {
	if (distanciaPersonagens(p) <= alcance)
		return true;
	return false;
}

void Personagem::ataca(Personagem* p) {
	if(acertouAtaque(p))
		p->tomaDano(dano);
}