#pragma once
#include "entidade.h"

class Personagem : public Entidades::Entidade {
protected:
	int vida;
	bool atacando;
	int dano;
	float alcance;
	bool podeAtacar;
	float duracaoCooldown;
	float timerCooldown;
	bool olhaDireita;

public:
	Personagem(sf::Vector2f pos);
	~Personagem();
	virtual void executar() = 0;
	void setVida(int v);
	int getVida();
	bool getAtacando();
	int getDano();
	void tomaDano(int ferimento);
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