#include "explorador.h"

Explorador::Explorador() :Jogador()
{
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
	window->draw(sprite);
}