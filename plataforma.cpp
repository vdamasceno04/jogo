#include "Plataforma.h"

Plataforma::Plataforma(sf::Vector2f pos, ID i) :
	Obstaculo(pos, i)
{ 
	id = i;
	setSprite("C:/Users/genti/Downloads/texturas/chao2.png");
	setPosition(pos);;
	body.setSize(sf::Vector2f(67, 69));
	body.setScale(2, 2);
	sprite.setScale(2, 2);
}

Plataforma::~Plataforma() {}

void Plataforma::executar() {
	renderizar();
}