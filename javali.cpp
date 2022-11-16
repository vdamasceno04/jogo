#include"javali.h"

Javali::Javali(sf::Vector2f pos, Jogador* p1, Jogador* p2, int v, int d, int vs, ID i) :
	Inimigo(pos, p1, p2, v, d, i) {
	id = i;
	vida = v;
	dano = d;
	visao = vs;
	setSprite("C:/Users/genti/Downloads/texturas/javalimarrom.png");
	body.setSize(sf::Vector2f(47, 32));
	setEscala(sf::Vector2f(4, 4));
	setPosicao(pos);
	velocidade = (sf::Vector2f(0.35, 0.35));
	alcance = 20;
	duracaoCooldown = 150.5;
}

Javali::~Javali() {}

void Javali::executar() {
	hostilizar();
	remover();
	renderizar();
}