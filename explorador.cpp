#include "explorador.h"

Explorador::Explorador(sf::Vector2f pos) :Jogador(pos)
{
	id = explorador;
	setSprite("C:/Users/genti/Downloads/texturas/Idle.gif");
}

Explorador::~Explorador() {}

void Explorador::controlar()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		setPosicao(sf::Vector2f(getPosicao().x + VMAXX, getPosicao().y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		setPosicao(sf::Vector2f(getPosicao().x - VMAXX, getPosicao().y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		setPosicao(sf::Vector2f(getPosicao().x, getPosicao().y - VMAXY));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		setPosicao(sf::Vector2f(getPosicao().x, getPosicao().y + VMAXY));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) {
		ataca();
	}
	body.setPosition(sprite.getPosition());
}

void Explorador::executar() {
	controlar();
	remover();
	renderizar();
}

void Explorador::colidir(Entidade* pEnt, ID id) {
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