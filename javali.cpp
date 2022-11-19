#include"javali.h"
#include"jogador.h"

#define VMAXX 0.35
#define VMAXY 0

Javali::Javali(sf::Vector2f pos, Jogador* p1, Jogador* p2, int i) :
	Inimigo(pos, p1, p2) {
	id = javali;
	setSprite("C:/Users/genti/Downloads/texturas/javalimarrom.png");
	sprite.setTextureRect(sf::IntRect(4, 4, 39, 30));
	body.setSize(sf::Vector2f(120, 100));
	setEscala(sf::Vector2f(4, 4));
	setPosicao(pos);
	velocidade = (sf::Vector2f(VMAXX, VMAXY));
	alcance = 20;
	duracaoCooldown = 150.5;
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
	renderizar();
}

void Javali::ataca(Jogador* pJ) {
	atualizapodeAtacar();
	if (acertaAtaque(pJ) && getPersegue(pJ)) {
		golpear(pJ);
	}
}

void Javali::colidir(Entidade* p, float intersec_x, float intersec_y)
{
	if (p->getId() == 1 || p->getId() == 2 || p->getId() == 3 || p->getId() == 6 || p->getId() == 7)
		resolverColisao(p, intersec_x, intersec_y);
	/*	else if (ent2->getId() == 4) {
			vida -= ent2->getDamage();
			if (vida<= 0) {
				morreu();
			}
		*/
}