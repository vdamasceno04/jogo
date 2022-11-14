#include "abelha.h"

Abelha::Abelha(sf::Vector2f pos, sf::Vector2f tam, int v, int d, float dC, float dA, float vR, bool p, Jogador* pJ):
Inimigo(pos,tam, v, d, dC, dA, vR, p, pJ){
	textura.loadFromFile("C:/Users/genti/Downloads/abelha2.png");
	sprite.setTexture(textura);
	body.setSize(size);
	body.setScale(2, 2);
	sprite.setScale(2, 2);
	body.setPosition(pos);
	sprite.setPosition(pos);
	setVelocidade(sf::Vector2f(0.5, 0.5));
}

Abelha::~Abelha(){}


void Abelha::executar(){
	setPerseguir();
	perseguicao();
	window->draw(sprite); 
}