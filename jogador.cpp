#include"jogador.h"

Jogador::Jogador(sf::Vector2f position, sf::Vector2f size, int v, int d, float dC, float dA):
Personagem::Personagem(position, size, v, d, dC, dA)
{
	textura.loadFromFile("C:/Users/genti/Downloads/Legacy-Fantasy-VL.1 - High Forest - Update 1.9/Character/Idle/Idle.gif");
	sprite.setTexture(textura);
	body.setSize(sf::Vector2f(50, 50));
}

Jogador::~Jogador() {}

void Jogador::executar()
{
	move();
	window->draw(sprite);
}

void Jogador::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		sprite.move(sf::Vector2f(0.1f, 0.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		sprite.move(sf::Vector2f(-0.1f, 0.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		sprite.move(sf::Vector2f(0.f, -0.1f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		sprite.move(sf::Vector2f(0.f, 0.1f));
	}

}
