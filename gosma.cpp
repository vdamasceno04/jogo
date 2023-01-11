#include "gosma.h"
#include "caracol.h"

#define VMAXX 15
#define VMAXY -29.8
Gosma::Gosma(Math::CoordF pos, int ven) : Entidades::Entidade(pos) {
	id = gosma;
	setPosicao(Math::CoordF(pos.x +20, pos.y+60));
	setEscala(Math::CoordF(2, 2));
	setTamanho(Math::CoordF(4, 8));
	veneno = ven;
	vmax.x = VMAXX;
	vmax.y = VMAXY;
	setVelocidade(Math::CoordF(-vmax.x, vmax.y));
	setSprite("Assets/gosma.png");
	inicializar();
}

Gosma::~Gosma() {}

void Gosma::inicializar() {
	setVelocidade(Math::CoordF(-vmax.x, vmax.y));
	dano = veneno - 1;
}

void Gosma::setCaracol(Caracol* pCar) {
	pCaracol = pCar;
}

void Gosma::efeito(Entidade* p) {
	p->tomaDano(dano);
	colidindo = true;
}

void Gosma::executar() {
	if (pCaracol->getCuspir() || (this->getPosicao().x - 20 != pCaracol->getPosicao().x)) {
		atualizar();
	}
	if (colidindo) {
		inicializar();
		setPosicao(Math::CoordF(pCaracol->getPosicao().x + 20, pCaracol->getPosicao().y + 60));
		setColidindo(false);
		if(pCaracol->getRemove())
			setRemove(true);
	}
	renderizar();
}