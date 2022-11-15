#pragma once
#include "entidade.h"

class Personagem : public Entidades::Entidade {
protected:
	int vida;
	bool atacando;
	bool atacou;
	int dano;
	float alcance;
	bool podeAtacar;
	float timerAtaque;
	float duracaoCooldown;
	float timerCooldown;
	float duracaoAtaque;
	bool olhaDireita;

public:
	Personagem(sf::Vector2f pos, sf::Vector2f tam, int v, int d, float alc, float dC, float dA);
	~Personagem();
	virtual void executar() = 0;
	void setVida(int v);
	int getVida();
	void tomaDano(int ferimento);
	bool morreu();
	void setOlhar(bool direita);
	bool getOlharDireita();
	void contaTempoAtaque(const float dt);
	void atualizapodeAtacar();
//	void ataca(Personagem* p);
	float distanciaPersonagens(Personagem* pP);
	bool acertaAtaque(Personagem* p);
	void remover();
};