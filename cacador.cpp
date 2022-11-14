#include "cacador.h"

Cacador::Cacador():Jogador()
{
}
Cacador::~Cacador() {}
void Cacador::move() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		sprite.move(sf::Vector2f(2.f, 0.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		sprite.move(sf::Vector2f(-2.f, 0.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		sprite.move(sf::Vector2f(0.f, -2.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		sprite.move(sf::Vector2f(0.f, 2.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
//		ataca();
	}	
	body.setPosition(sprite.getPosition());
}
void Cacador::executar() {
	move();
	morreu();
	window->draw(sprite);
}