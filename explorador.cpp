#include "explorador.h"

Explorador::Explorador(sf::Vector2f pos) :Jogador(pos)
{
	setSprite("C:/Users/genti/Downloads/Legacy-Fantasy-VL.1 - High Forest - Update 1.9/Character/Idle/Idle.gif");
}

Explorador::~Explorador(){}

void Explorador::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		sprite.move(sf::Vector2f(2.f, 0.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		sprite.move(sf::Vector2f(-2.f, 0.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		sprite.move(sf::Vector2f(0.f, -2.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		sprite.move(sf::Vector2f(0.f, 2.f));
	}
	body.setPosition(sprite.getPosition());
}
void Explorador::executar() {
	move();
	remover();
	renderizar();
}