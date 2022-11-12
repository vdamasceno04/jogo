#include"jogador.h"
#include<iostream>
using std::cout;
using std::endl;

Jogador::Jogador(sf::Vector2f pos, sf::Vector2f size, int v, int d, float dC, float dA):
Personagem::Personagem(pos, size, v, d, dC, dA)
{
//	pGG->loadTexture("C:/Users/genti/Downloads/Legacy-Fantasy-VL.1 - High Forest - Update 1.9/Character/Idle/Idle.gif");
	textura.loadFromFile("C:/Users/genti/Downloads/Legacy-Fantasy-VL.1 - High Forest - Update 1.9/Character/Idle/Idle.gif");
	sprite.setTexture(textura);
	body.setSize(size);
	body.setScale(2,2);
	sprite.setScale(2, 2);
	body.setPosition(pos);
	sprite.setPosition(pos);
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
		body.move(sf::Vector2f(0.91f, 0.f));
		sprite.move(sf::Vector2f(0.91f, 0.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		body.move(sf::Vector2f(-0.91f, 0.f));
		sprite.move(sf::Vector2f(-0.91f, 0.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		body.move(sf::Vector2f(0.f, -0.91f));
		sprite.move(sf::Vector2f(0.f, -0.91f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		body.move(sf::Vector2f(0.f, 0.91f));
		sprite.move(sf::Vector2f(0.f, 0.91f));
	}

}
