#include "Agua.h"
#include "personagem.h"


#define LENTIDAO 0.2

Agua::Agua(Math::CoordF pos) :
	Obstaculo(pos)
{
	id = agua;
	lentidao = LENTIDAO;
	setTamanho(Math::CoordF(100, 137));
	setSprite("Assets/agua.png");
	sprite.setTextureRect(sf::IntRect(0,5,60,60 ));
	setPosicao(pos);
	setEscala(Math::CoordF(3, 4));
}

Agua::~Agua() {}

float Agua::getLentidao() { return lentidao; }

void Agua::efeito(Entidade* p) {
	p->setVelocidade(Math::CoordF(p->getVelocidade().x * lentidao, p->getVelocidade().y));
}

void Agua::executar() {
	renderizar();
	atualizar();
}