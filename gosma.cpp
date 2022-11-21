#include "gosma.h"
#include "caracol.h"

Gosma::Gosma(sf::Vector2f pos, int ven) : Entidades::Entidade(pos) {
	id = gosma;
	setPosicao(sf::Vector2f(pos.x +50, pos.y+85));
	setEscala(sf::Vector2f(2, 2));
	body.setSize(sf::Vector2f(4, 8));
	veneno = ven;
	dano = veneno * 2;
	vmax.x = 25;
	vmax.y = -19.8;
	setSprite("C:/Users/genti/Downloads/texturas/gosma.png");
	sprite.rotate(180);
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
		setPosicao(sf::Vector2f(pCaracol->getPosicao().x + 50, pCaracol->getPosicao().y + 85));
		inicializar();
	}
	else if (p->getId() == 1 || p->getId() == 2) {
		resolverColisao(p, intersec_x, intersec_y);
		setPosicao(sf::Vector2f(pCaracol->getPosicao().x + 50, pCaracol->getPosicao().y + 85));
		inicializar();
		efeito(p);
	}
}

void Gosma::efeito(Entidade* p) {
	p->tomaDano(dano);
}

void Gosma::executar() {
	atualizar();
	renderizar();
}