#include "cacador.h"

#define VIDA 20
Cacador::Cacador(sf::Vector2f pos) :
	Jogador(pos) {
	id = cacador;
	setSprite("Assets/Cacador.gif");
	sprite.setTextureRect(sf::IntRect(11, 11, 47, 59));
}
Cacador::~Cacador() {}

void Cacador::resetar() {
	setVida(VIDA);
	setPosicao(sf::Vector2f(300, HEIGHT * 0.635));
}

void Cacador::controlar() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (getVelocidade().x == vmax.x || getVelocidade().x == 0)) {
		setVelocidade(sf::Vector2f(vmax.x, getVelocidade().y));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (getVelocidade().x == - vmax.x || getVelocidade().x == 0)){
		setVelocidade(sf::Vector2f(-vmax.y, getVelocidade().y));
	}
	else
		setVelocidade(sf::Vector2f(0, getVelocidade().y));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && getColidindo()) {
		velocidade.y = -vmax.y;
		setColidindo(false);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		ataca();
	}
	body.setPosition(sprite.getPosition());

}
void Cacador::executar() {
	controlar();
	atualizar();
	remover();
	renderizar();
}
