#include "fundo.h"

Fundo::Fundo(sf::Vector2f pos, bool d) : Entidade(pos)
{
	dia = d;
	id = fundo;
	if(dia)
		setSprite("C:/Users/usuario/Desktop/OmegaCringe/Assets/fundo.png");
	else
		setSprite("C:/Users/usuario/Desktop/OmegaCringe/Assets/fundonoite.png");
	body.setSize(sf::Vector2f(WIDTH, HEIGHT));;
	setEscala(sf::Vector2f(3.21, 3.75));
	setPosicao(pos);
}

Fundo::~Fundo() {}

void Fundo::executar() {
	renderizar();
}