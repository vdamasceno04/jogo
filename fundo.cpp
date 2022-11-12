#include "fundo.h"

Fundo::Fundo(sf::Vector2f pos, sf::Vector2f tam): Entidade(pos, tam)
{
	textura.loadFromFile("C:/Users/genti/Downloads/Legacy-Fantasy-VL.1 - High Forest - Update 1.9/Background/Background.png");
	sprite.setTexture(textura);
	body.setSize(sf::Vector2f(WIDTH, HEIGHT));;
	sprite.setScale(sf::Vector2f(3.21, 3.75));
	body.setPosition(pos);
	sprite.move(pos);
}

Fundo::~Fundo() {}

void Fundo::executar() {
	window->draw(sprite);
}
