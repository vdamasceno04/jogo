#include "Espinho.h"
#include "personagem.h"

Espinho::Espinho(sf::Vector2f pos) :
	Obstaculos::Obstaculo(pos)
{
	id = espinho;
	dano = 1;
	danificar = true;
	duracaoCooldown = 100;
	setSprite("Assets/espinho.png");
	body.setSize(sf::Vector2f(67, 137));
	setPosicao(pos);
	setEscala(sf::Vector2f(2, 2));
}

Espinho::~Espinho() {}

bool Espinho::getDanificar() { return danificar; }

float Espinho::getCooldown() { return duracaoCooldown; }

void Espinho::efeito(Entidade* pEnt) {
	if (danificar) {
		danificar = false;
		pEnt->tomaDano(dano);
		timerCooldown = 0;
		pGG->getClock().restart();
		timerCooldown += pGG->getClock().getElapsedTime().asSeconds();

	}
	else {
		pGG->getClock().restart();
		timerCooldown += pGG->getClock().getElapsedTime().asSeconds();
	}
	atualizaDanificar();
}

void Espinho::contaTempoCooldown(const float dt) {
	if (danificar) {
		timerCooldown = 0;
		danificar = false;
	}
	else
		timerCooldown += dt;
}

void Espinho::atualizaDanificar()
{
	if (duracaoCooldown <= timerCooldown)
		danificar = true;
	else
		danificar = false;
}


void Espinho::executar() {
	renderizar();
	atualizar();
}

