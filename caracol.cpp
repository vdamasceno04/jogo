#include "caracol.h"
#include "jogador.h"

Caracol::Caracol(sf::Vector2f pos, Jogador* p1, Jogador* p2, int ven) :
	Inimigo(pos, p1, p2) {
	id = caracol;

	setSprite("C:/Users/genti/Downloads/texturas/abelha2.png");
	sprite.setTextureRect(sf::IntRect(10, 1, 55, 59));
	body.setSize(sf::Vector2f(40, 76));
	setEscala(sf::Vector2f(2, 2));
	setPosicao(pos);
	alcance = 60;
	duracaoCooldown = 400.5;
	veneno = ven;
	inicializa(veneno);
	vmax.x = 5.0;
	velocidade.y = 0;
}

Caracol::~Caracol() {}

void Caracol::inicializa(int veneno) {
	vida = veneno;
	dano = veneno - 1;
	visao = (veneno* 100);
}

void Caracol::ataca(Jogador* pJ) {
	atualizapodeAtacar();
	if (acertaAtaque(pJ) && getPersegue(pJ)) {
		golpear(pJ);
	}
}

void Caracol::executar() {
	hostilizar();
	remover();
	atualizar();
	renderizar();
}

void Caracol::colidir(Entidade* p, float intersec_x, float intersec_y)
{
	if (p->getId() == 1 || p->getId() == 2 || p->getId() == 3 || p->getId() == 6 || p->getId() == 7)
		resolverColisao(p, intersec_x, intersec_y);
}