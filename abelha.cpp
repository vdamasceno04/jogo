#include "abelha.h"

Abelha::Abelha(sf::Vector2f pos, sf::Vector2f tam, int v, int d, float dC, float dA, float vR):
Inimigo(pos,tam, v, d, dC, dA, vR){
	textura.loadFromFile("C:/Users/genti/Downloads/abelha.png");
	sprite.setTexture(textura);
	body.setSize(size);
	body.setScale(2, 2);
	sprite.setScale(2, 2);
	body.setPosition(pos);
	sprite.setPosition(pos);
}

Abelha::~Abelha(){}


void Abelha::executar(){ window->draw(sprite); }