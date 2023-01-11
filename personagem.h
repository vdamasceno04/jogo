#pragma once
#include "entidade.h"

class Personagem : public Entidades::Entidade {
protected:
	bool atacando;
	float alcance;
	bool podeAtacar;
	float duracaoCooldown;
	float timerCooldown;
	bool olhaDireita;

public:
	Personagem(Math::CoordF pos);
	~Personagem();
	virtual void executar() = 0;
	void setVida(int v);
	int getVida();
	bool getAtacando();
	bool morreu();
	void setOlhar(bool direita);
	bool getOlharDireita();
	float getAlcance();
	void contaTempoAtaque(const float dt);
	void atualizapodeAtacar();
	float distanciaPersonagens(Personagem* pP);
	bool acertaAtaque(Personagem* p);
	void golpear(Personagem* p);
	void remover();
};