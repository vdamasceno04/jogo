#include "Plataforma.h"

Plataforma::Plataforma(sf::Vector2f pos, bool verm) :
	Obstaculo(pos)
{
	vermelho = verm;
	id = plataforma;
	if(vermelho)
		setSprite("C:/Users/genti/Downloads/texturas/chaovermelho.png");
	else
		setSprite("C:/Users/genti/Downloads/texturas/chaoverde.png");
	setPosicao(pos);
	body.setSize(sf::Vector2f(67, 69));
	setEscala(sf::Vector2f(2, 2));
}

Plataforma::~Plataforma() {}

void Plataforma::executar() {
	renderizar();
}