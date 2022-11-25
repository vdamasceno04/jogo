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
}

Gosma::~Gosma() {}

void Gosma::inicializar() {
	setVelocidade(sf::Vector2f(-vmax.x, vmax.y));
}

void Gosma::setCaracol(Caracol* pCar) {
	pCaracol = pCar;
}

void Gosma::colidir(Entidade* p, float intersec_x, float intersec_y) {
	if (p->getId() == 3 || p->getId() == 6 || p->getId() == 5 || p->getId() == 4 || p->getId() == 7) {
		resolverColisao(p, intersec_x, intersec_y);
		setPosicao(sf::Vector2f(pCaracol->getPosicao().x + 20, pCaracol->getPosicao().y + 60));
		inicializar();
		
	}
	else if (p->getId() == 1 || p->getId() == 2) {
		resolverColisao(p, intersec_x, intersec_y);
		setPosicao(sf::Vector2f(pCaracol->getPosicao().x + 20, pCaracol->getPosicao().y + 60));
		inicializar();
		efeito(p);
		
	}
	if (pCaracol->getRemove()  && p->getId() != 10) {
		setRemove(true);
	}
}

void Gosma::efeito(Entidade* p) {
	p->tomaDano(dano);
}

void Gosma::executar() {
	if (pCaracol->getCuspir() || (this->getPosicao().x - 40 != pCaracol->getPosicao().x)) {
		atualizar();
	}
	renderizar();
}