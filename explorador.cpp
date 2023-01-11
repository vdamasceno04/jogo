#include "explorador.h"

Explorador::Explorador(Math::CoordF pos) :Jogador(pos)
{
	id = explorador;
	setSprite("Assets/Explorador.png");
	sprite.setTextureRect(sf::IntRect(11, 11, 47, 59));
}

Explorador::~Explorador() {}

void Explorador::resetar() {
	setVida(20);
	setPosicao(Math::CoordF(0, HEIGHT * 0.635));
}
void Explorador::controlar()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (getVelocidade().x == vmax.x|| getVelocidade().x == 0)) {
		setVelocidade(Math::CoordF(vmax.x, getVelocidade().y));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (getVelocidade().x == -vmax.x|| getVelocidade().x == 0)) {
		setVelocidade(Math::CoordF(-vmax.x, getVelocidade().y));
	}
	else
		setVelocidade(Math::CoordF(0, getVelocidade().y));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && getColidindo()) {
		velocidade.y = -vmax.y;
		setColidindo(false);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) {
		ataca();
	}
	body.setPosition(sprite.getPosition());
}

void Explorador::executar() {
	controlar();
	remover();
	atualizar();
	renderizar();
}
