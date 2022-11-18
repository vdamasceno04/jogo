#include "cacador.h"

Cacador::Cacador(sf::Vector2f pos) :
	Jogador(pos) {
	id = cacador;
	setSprite("C:/Users/genti/Downloads/texturas/Idle.gif");
}
Cacador::~Cacador() {}

void Cacador::controlar() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		setPosicao(sf::Vector2f(getPosicao().x + VMAXX, getPosicao().y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		setPosicao(sf::Vector2f(getPosicao().x - VMAXX, getPosicao().y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		setPosicao(sf::Vector2f(getPosicao().x, getPosicao().y - VMAXY));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
		setPosicao(sf::Vector2f(getPosicao().x, getPosicao().y + VMAXY));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		ataca();
	}
	body.setPosition(sprite.getPosition());

}
void Cacador::executar() {
	controlar();
	remover();
	renderizar();
}

void Cacador::colidir(Entidade* pEnt, ID id) {
	sf::Vector2f posEnt2 = pEnt->getPosicao();
	int lado = 0;
	if (pEnt->getId() == plataforma)
	{
		//Colisão por Cima
		if (lado == 0)
		{
			setPosicao(sf::Vector2f(sprite.getPosition().x, posEnt2.y - 120.0f));
			getBody().setPosition(sf::Vector2f(sprite.getPosition().x, posEnt2.y - 120.0f));
			sprite.setPosition(sf::Vector2f(sprite.getPosition().x, posEnt2.y - 120.0f));
		}
		/*
		//Colisão por Baixo
		else if (lado == 1)
		{
			setPosition(sf::Vector2f(getPosition().x, posEnt2.y));
			getBody().setPosition(sf::Vector2f(getPosition().x, posEnt2.y));
			sprite.setPosition(sf::Vector2f(getPosition().x, posEnt2.y));
		}
		//Colisão pela Direita
		else if (lado == 2)
		{
			setPosition(sf::Vector2f(pEnt2->getLadoEsquerdo(), getPosition().y));
			getBody().setPosition(sf::Vector2f(pEnt2->getLadoEsquerdo(), getPosition().y));
			sprite.setPosition(sf::Vector2f(pEnt2->getLadoEsquerdo(), getPosition().y));
		}
		//Colisão pela Esquerda
		else if (lado == 3)
		{
			setPosition(sf::Vector2f(pEnt2->getLadoDireito(), getPosition().y));
			getBody().setPosition(sf::Vector2f(pEnt2->getLadoDireito(), getPosition().y));
			sprite.setPosition(sf::Vector2f(pEnt2->getLadoDireito(), getPosition().y));
		}
		*/
	}
}