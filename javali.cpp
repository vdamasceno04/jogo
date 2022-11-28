#include"javali.h"
#include"jogador.h"

#define VMAXX 3.5
#define ALCANCE 70
#define COOLDOWN 150.5

Javali::Javali(sf::Vector2f pos, Jogador* p1, Jogador* p2, int i) :
	Inimigo(pos, p1, p2) {
	id = javali;
	setSprite("Assets/javalimarrom.png");
	sprite.setTextureRect(sf::IntRect(4, 4, 39, 30));
	body.setSize(sf::Vector2f(120, 110));
	setEscala(sf::Vector2f(4, 4));
	setPosicao(pos);
	vmax = (sf::Vector2f(VMAXX, 0));
	alcance = ALCANCE;
	duracaoCooldown = COOLDOWN;
	idade = i;
	inicializa(idade);
}

Javali::~Javali() {}

void Javali::inicializa(int i) {
	vida = idade + 15;
	dano = idade - 1;
	visao = (idade * 10) + 500;
}
void Javali::executar() {
	hostilizar();
	remover();
	atualizar();
	renderizar();
}

void Javali::ataca(Jogador* pJ) {
	atualizapodeAtacar();
	if (acertaAtaque(pJ) && getPersegue(pJ)) {
		golpear(pJ);
	}
}