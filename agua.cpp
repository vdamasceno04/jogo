#include "Agua.h"
#include "personagem.h"

Agua::Agua(sf::Vector2f pos) :
	Obstaculo(pos)
{
	id = agua;
	lentidao = 0.8;
	body.setSize(sf::Vector2f(100, 37));
	setSprite("C:/Users/genti/Downloads/texturas/agua.png");
	sprite.setTextureRect(sf::IntRect(0,5,60,60 ));
	setPosicao(pos);
	setEscala(sf::Vector2f(3, 4));
}

Agua::~Agua() {}

float Agua::getLentidao() { return lentidao; }

void Agua::efeito(Entidade* p) {
	p->setVelocidade(getVelocidade() * lentidao);
}

void Agua::executar() {
	renderizar();
}