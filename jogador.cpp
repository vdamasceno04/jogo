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
	alcance = 100;
	vmax= sf::Vector2f(15.0, 25.0);
}

Jogador::~Jogador() {}

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