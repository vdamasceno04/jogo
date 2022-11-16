#include "fundo.h"

Fundo::Fundo(sf::Vector2f pos): Entidade(pos)
{
	setSprite("C:/Users/genti/Downloads/Legacy-Fantasy-VL.1 - High Forest - Update 1.9/Background/Background.png");
	body.setSize(sf::Vector2f(WIDTH, HEIGHT));;
	sprite.setScale(sf::Vector2f(3.21, 3.75));
	setPosition(pos);
}

Fundo::~Fundo() {}

void Fundo::executar() {
	renderizar();
}
