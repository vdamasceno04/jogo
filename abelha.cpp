#include "abelha.h"
#include "jogador.h"

#define VMAXX 5.0
#define ALCANCE 60
#define COOLDOWN 400.5

Abelha::Abelha(Math::CoordF pos, Jogador* p1, Jogador* p2, int m) :
	Inimigo(pos, p1, p2) {
	id = abelha;

	setSprite("Assets/abelha2.png");
	sprite.setTextureRect(sf::IntRect(10, 1, 55, 59));
	setTamanho(Math::CoordF(40, 76));
	setEscala(Math::CoordF(2, 2));
	setPosicao(pos);
	alcance = ALCANCE;
	duracaoCooldown = COOLDOWN;
	mel = m;
	inicializa(mel);
	vmax.x = VMAXX;
	velocidade.y = 0;
}

Abelha::~Abelha() {}

void Abelha::voar(){
	float dt = 0.1;
	setPosicao(Math::CoordF(getPosicao().x, getPosicao().y + (getVelocidade().y * dt) + GRAVIDADE * dt * dt / 2));
	setVelocidade(Math::CoordF(getVelocidade().x, getVelocidade().y - GRAVIDADE * dt));
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