#include "Espinho.h"
#include "personagem.h"

Espinho::Espinho(sf::Vector2f pos) :
	Obstaculos::Obstaculo(pos)
{
	id = espinho;
	dano = 10;
	danificar = true;
	duracaoCooldown = 100;
	setSprite("C:/Users/genti/Downloads/texturas/espinho.png");
	body.setSize(sf::Vector2f(67, 28));
	setPosicao(pos);
	setEscala(sf::Vector2f(2, 2));
}

Espinho::~Espinho() {}

int Espinho::getDano() { return dano; }

bool Espinho::getDanificar() { return danificar; }

float Espinho::getCooldown() { return duracaoCooldown; }

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

void Espinho::efeito(Personagem* p){
	{
		if (danificar) {
			p->tomaDano(dano);
			danificar = false;
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
}

void Espinho::executar() {
	renderizar();
}

