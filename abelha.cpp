#include "abelha.h"

Abelha::Abelha(sf::Vector2f pos, Jogador* p1, Jogador* p2, int v, int d, ID i):
Inimigo(pos, p1, p2, v, d, id){
	id = i;
	vida = v;
	dano = d;
	setSprite("C:/Users/genti/Downloads/texturas/abelha2.png");
	body.setSize(sf::Vector2f(61, 56));
	setEscala(sf::Vector2f(2, 2));
	setPosicao(pos);
	dano = 1;
	velocidade = (sf::Vector2f(0.5, 0.5));
	alcance = 10;
	duracaoCooldown = 100.5;
	visao = 250;
}

Abelha::~Abelha(){}

void Abelha::executar(){
	hostilizar();
	remover();
	renderizar();
}