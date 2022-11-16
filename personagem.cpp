#include "personagem.h"

Personagem::Personagem(sf::Vector2f pos):
Entidade::Entidade(pos) {
	atacando = false;
	atacou = false;
	podeAtacar = true;
	olhaDireita = true;
	timerAtaque = 0;
	timerCooldown = 0;
	setPosition(pos);
}

Personagem::~Personagem(){}

void Personagem::setVida(int v) { vida = v; }

int Personagem::getVida() { return vida; }

void Personagem::setVelocidade(sf::Vector2f vel) { velocidade = vel; }

sf::Vector2f Personagem::getVelocidade() { return velocidade; }

void Personagem::tomaDano(int ferimento) { vida -= ferimento;}

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
	if (atacou) {
		timerCooldown = 0;
		atacou = false;
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

void Personagem::remover() {
	if (morreu())
		remove = true;
}