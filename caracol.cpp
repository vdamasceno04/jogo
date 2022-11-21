#include "caracol.h"
#include "jogador.h"

Caracol::Caracol(sf::Vector2f pos, Jogador* p1, Jogador* p2, int ven, Gosma* pGosma) :
	Inimigo(pos, p1, p2) {
	id = caracol;
	gosma = pGosma;
	setSprite("C:/Users/genti/Downloads/texturas/caracol.png");
	body.setSize(sf::Vector2f(100, 89));
	setEscala(sf::Vector2f(4, 4));
	setPosicao(pos);
	alcance = 400;
	duracaoCooldown = 0.5;
	veneno = ven;
	inicializa(veneno);
	vmax.x = 0;
	velocidade.y = 0;
	pGosma->setCaracol(this);
}

Caracol::~Caracol() { }

void Caracol::inicializa(int veneno) {
	vida = veneno;
	visao = (veneno* 100);
}


void Caracol::cuspir() {
	gosma->executar();
}

void Caracol::removerGosma() {
	if (remove == true)
		gosma->setRemove(true);
}
void Caracol::executar() {
	remover();
	atualizar();
	atacado(pJ1);
	atacado(pJ2);
	cuspir();
	renderizar();
}

void Caracol::colidir(Entidade* p, float intersec_x, float intersec_y)
{
	if (p->getId() == 1 || p->getId() == 2 || p->getId() == 3 || p->getId() == 6
		|| p->getId() == 7 || p->getId() == 8)

		resolverColisao(p, intersec_x, intersec_y);

	else if (p->getId() == 5 || p->getId() == 4) {
		resolverColisao(p, intersec_x, intersec_y);
		p->efeito(this);
	}

}