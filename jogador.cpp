#include"jogador.h"

Jogador::Jogador():
Entidade::Entidade()
{
	body.setFillColor(sf::Color::Blue);
	body.setPosition(sf::Vector2f(200.f, 200.f));
}

Jogador::~Jogador() {}

void Jogador::executar()
{}

void Jogador::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		body.move(sf::Vector2f(0.1f, 0.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		body.move(sf::Vector2f(-0.1f, 0.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		body.move(sf::Vector2f(0.f, -0.1f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		body.move(sf::Vector2f(0.f, 0.1f));
	}

}