#include "abelha.h"

Abelha::Abelha(sf::Vector2f pos, Jogador* p1, Jogador* p2, ID i):
Inimigo(pos, p1, p2, id){
	id = i;
	setSprite("C:/Users/genti/Downloads/texturas/abelha2.png");
	body.setSize(sf::Vector2f(61, 56));
	body.setScale(2, 2);
	sprite.setScale(2, 2);
	setPosition(pos);
	dano = 1;
	velocidade = (sf::Vector2f(0.5, 0.5));
	alcance = 10;
	duracaoCooldown = 100.5;
	viewRange = 250;
}

Abelha::~Abelha(){}

void Abelha::executar(){
	hostilizar();
	renderizar();
}