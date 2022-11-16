#include "cacador.h"

Cacador::Cacador(sf::Vector2f pos, ID i):
	Jogador(pos, i){
	id = i;
	setSprite("C:/Users/genti/Downloads/Legacy-Fantasy-VL.1 - High Forest - Update 1.9/Character/Idle/Idle.gif");
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
	remover();
	renderizar();
}