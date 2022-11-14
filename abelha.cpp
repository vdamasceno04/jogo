#include "abelha.h"

Abelha::Abelha(sf::Vector2f pos, sf::Vector2f tam, int v, int d, float alc, float dC, float dA, float vR, Jogador* p1, Jogador* p2):
Inimigo(pos,tam, v, d, alc, dC, dA, vR, p1, p2){
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
	if (setPersegue(pJ1) || setPersegue(pJ2))
		perseguicao(setPerseguido(pJ1, pJ2));
	window->draw(sprite); 
	ataca(pJ1);
	ataca(pJ2);
}