#include "abelha.h"
#include "jogador.h"

Abelha::Abelha(sf::Vector2f pos, Jogador* p1, Jogador* p2, int m) :
	Inimigo(pos, p1, p2) {
	id = abelha;

	setSprite("C:/Users/genti/Downloads/texturas/abelha2.png");
	sprite.setTextureRect(sf::IntRect(10, 1, 55, 59));
	body.setSize(sf::Vector2f(40, 76));
	setEscala(sf::Vector2f(2, 2));
	setPosicao(pos);
	velocidade = (sf::Vector2f(0.5, 0.5));
	alcance = 10;
	duracaoCooldown = 100.5;
	mel = m;
	inicializa(mel);
}

Abelha::~Abelha() {}

void Abelha::inicializa(int m) {
	vida = mel;
	dano = 0;// mel - 1;
	visao = (mel * 100);
}

void Abelha::ataca(Jogador* pJ) {
	atualizapodeAtacar();
	if (acertaAtaque(pJ) && getPersegue(pJ)) {
		golpear(pJ);
	}
}

void Abelha::executar() {
	hostilizar();
	remover();
	renderizar();
}

void Abelha::colidir(Entidade* p, float intersec_x, float intersec_y)
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