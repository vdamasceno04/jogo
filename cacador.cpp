#include "cacador.h"

Cacador::Cacador(sf::Vector2f pos) :
	Jogador(pos) {
	id = cacador;
	setSprite("C:/Users/genti/Downloads/texturas/Idle.gif");
	sprite.setTextureRect(sf::IntRect(11, 11, 47, 59));
}
Cacador::~Cacador() {}

void Cacador::controlar() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		setPosicao(sf::Vector2f(getPosicao().x + VMAXX, getPosicao().y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		setPosicao(sf::Vector2f(getPosicao().x - VMAXX, getPosicao().y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		setPosicao(sf::Vector2f(getPosicao().x, getPosicao().y - VMAXY));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
		setPosicao(sf::Vector2f(getPosicao().x, getPosicao().y + VMAXY));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		ataca();
	}
	body.setPosition(sprite.getPosition());

}
void Cacador::executar() {
	controlar();
	remover();
	renderizar();
}
