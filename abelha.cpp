#include "abelha.h"

Abelha::Abelha(sf::Vector2f pos, sf::Vector2f tam, int v, int d, float dC, float dA, float vR, bool p, Jogador* p1, Jogador* p2):
Inimigo(pos,tam, v, d, dC, dA, vR, p, p1, p2){
	textura.loadFromFile("C:/Users/genti/Downloads/abelha2.png");
	sprite.setTexture(textura);
	body.setSize(size);
	body.setScale(2, 2);
	sprite.setScale(2, 2);
	body.setPosition(pos);
	sprite.setPosition(pos);
	setVelocidade(sf::Vector2f(0.3, 0.3));
}

Abelha::~Abelha(){}


void Abelha::executar(){
	setPerseguir(pJ1);
	setPerseguir(pJ2);
	perseguicao(pJ1);
	perseguicao(pJ2);
	window->draw(sprite); 
}