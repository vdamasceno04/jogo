#include "gosma.h"
#include "caracol.h"

Gosma::Gosma(sf::Vector2f pos, int ven, bool dir) : Entidades::Entidade(pos) {
	id = gosma;
	direita = dir;
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

}

Gosma::~Gosma() {}

void Gosma::inicializar() {
		if(direita)
			setVelocidade(sf::Vector2f(vmax.x, vmax.y));
		else
			setVelocidade(sf::Vector2f(-vmax.x, vmax.y));

}
void Gosma::colidir(Entidade* p, float intersec_x, float intersec_y) {
	if (p->getId() == 1 || p->getId() == 2 || p->getId() == 6
		|| p->getId() == 7 || p->getId() == 8 || p->getId() == 9 || p->getId() == 3)
		resolverColisao(p, intersec_x, intersec_y);
	this->~Gosma();

}

void Gosma::efeito(Entidade* p) {
	p->tomaDano(dano);
}

void Gosma::executar() {
	atualizar();
	renderizar();
}