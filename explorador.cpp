#include "explorador.h"

Explorador::Explorador(sf::Vector2f pos) :Jogador(pos)
{
	id = explorador;
	setSprite("C:/Users/genti/Downloads/texturas/Idle.gif");
	sprite.setTextureRect(sf::IntRect(11, 11, 47, 59));
}

Explorador::~Explorador() {}

void Explorador::controlar()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		setPosicao(sf::Vector2f(getPosicao().x + VMAXX, getPosicao().y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		setPosicao(sf::Vector2f(getPosicao().x - VMAXX, getPosicao().y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		setPosicao(sf::Vector2f(getPosicao().x, getPosicao().y - VMAXY));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		setPosicao(sf::Vector2f(getPosicao().x, getPosicao().y + VMAXY));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) {
		ataca();
	}
	body.setPosition(sprite.getPosition());
}

void Explorador::executar() {
	controlar();
	remover();
	renderizar();
}
