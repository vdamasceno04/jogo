#include"jogador.h"
#include"ListaEntidades.h"

Jogador::Jogador(sf::Vector2f pos) :
	Personagem::Personagem(pos)
{
	podeAtacar = true;
	setVida(20);
	body.setSize(sf::Vector2f(45, 100));
	setEscala(sf::Vector2f(2, 2));
	setPosicao(pos);
	duracaoCooldown = 30;
	dano = 3;
	alcance = 60;
}

Jogador::~Jogador() {}

void Jogador::colidir(Entidade* p, float intersec_x, float intersec_y)
{
	if (p->getId() == 1 || p->getId() == 2 || p->getId() == 3 || p->getId() == 6 || p->getId() == 7)
		resolverColisao(p, intersec_x, intersec_y);
	else if (p->getId() == 5) {
		resolverColisao(p, intersec_x, intersec_y);
	//	tomaDano(p->getDano()); EFEITO
	}
		
}

void Jogador::ataca()
{
	if (podeAtacar) {
		atacando = true;
		timerCooldown = 0;
		pGG->getClock().restart();
		timerCooldown += pGG->getClock().getElapsedTime().asSeconds();
	}
	else {
		atacando = false;
		pGG->getClock().restart();
		timerCooldown += pGG->getClock().getElapsedTime().asSeconds();
	}
	atualizapodeAtacar();

}