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
	alcance = 60;
	duracaoCooldown = 400.5;
	mel = m;
	inicializa(mel);
	vmax.x = 5.0;
	velocidade.y = 0;
}

Abelha::~Abelha() {}

void Abelha::voar(){
	float dt = 0.1;
	setPosicao(sf::Vector2f(getPosicao().x, getPosicao().y + (getVelocidade().y * dt) + GRAVIDADE * dt * dt / 2));
	setVelocidade(sf::Vector2f(getVelocidade().x, getVelocidade().y - GRAVIDADE * dt));
}

void Abelha::inicializa(int m) {
	vida = mel;
	dano = mel - 1;
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
	voar();
	atualizar();
	renderizar();
}

void Abelha::colidir(Entidade* p, float intersec_x, float intersec_y)
{
	if (p->getId() == 1 || p->getId() == 2 || p->getId() == 3 || p->getId() == 6 || p->getId() == 7)
		resolverColisao(p, intersec_x, intersec_y);
}