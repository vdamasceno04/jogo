#include"javali.h"

Javali::Javali(sf::Vector2f pos, Jogador* p1, Jogador* p2, int v, int d, int vs, ID i) :
	Inimigo(pos, p1, p2, v, d, i) {
	id = i;
	vida = v;
	dano = d;
	visao = vs;
	setSprite("C:/Users/genti/Downloads/texturas/javalimarrom.png");
	body.setSize(sf::Vector2f(47, 32));
	setEscala(sf::Vector2f(4, 4));
	setPosicao(pos);
	velocidade = (sf::Vector2f(0.35, 0.35));
	alcance = 20;
	duracaoCooldown = 150.5;
}

Javali::~Javali() {}

void Javali::executar() {
	hostilizar();
	remover();
	renderizar();
}

void Javali::colidir(Entidade* pEnt, ID id) {
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