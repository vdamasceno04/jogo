#include "gosma.h"
#include "caracol.h"

Gosma::Gosma(sf::Vector2f pos, int ven) : Entidades::Entidade(pos) {
	id = gosma;
	setPosicao(sf::Vector2f(pos.x +20, pos.y+60));
	setEscala(sf::Vector2f(2, 2));
	body.setSize(sf::Vector2f(4, 8));
	veneno = ven;
	dano = 0;//veneno -1;
	vmax.x = 15;
	vmax.y = -29.8;
	setVelocidade(sf::Vector2f(-vmax.x, vmax.y));
	setSprite("Assets/gosma.png");
	inicializar();
	remove = false;
	colidindo = false;
}

Gosma::~Gosma() {}

void Gosma::inicializar() {
	setVelocidade(sf::Vector2f(-vmax.x, vmax.y));
}

void Gosma::setCaracol(Caracol* pCar) {
	pCaracol = pCar;
}

void Gosma::efeito(Entidade* p) {
	p->tomaDano(dano);
}

void Gosma::executar() {
	if (pCaracol->getCuspir() || (this->getPosicao().x - 20 != pCaracol->getPosicao().x)) {
		atualizar();
	}
	if (colidindo) {
		inicializar();
		setPosicao(sf::Vector2f(pCaracol->getPosicao().x + 20, pCaracol->getPosicao().y + 60));
		setColidindo(false);
		if(pCaracol->getRemove())
			setRemove(true);
	}
	renderizar();
}