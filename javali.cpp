#include"javali.h"

Javali::Javali(sf::Vector2f pos, Jogador* p1, Jogador* p2, ID i) :
	Inimigo(pos, p1, p2, i) {
	id = i;
	setSprite("C:/Users/genti/Downloads/texturas/javalimarrom.png");
	body.setSize(sf::Vector2f(61, 56));
	body.setScale(2, 2);
	sprite.setScale(2, 2);
	setPosition(pos);
	dano = 5;
	velocidade = (sf::Vector2f(0.4, 0.4));
	alcance = 20;
	duracaoCooldown = 150.5;
	viewRange = 600;
}

Javali::~Javali() {}

void Javali::executar() {
	hostilizar();
	renderizar();
}