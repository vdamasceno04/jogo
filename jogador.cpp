#include"jogador.h"
#include"ListaEntidades.h"

Jogador::Jogador(sf::Vector2f pos, ID i):
Personagem::Personagem(pos, i)
{
	podeAtacar = true;
	setVida(20);
	body.setSize(tamanho);
	setEscala(sf::Vector2f(2, 2));
	setPosicao(pos);
	duracaoCooldown = 30;
	dano = 3;
	alcance = 20;
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
