#pragma once
#include "entidade.h"

class Personagem : public Entidades::Entidade {
protected:
	int vida;
	sf::Vector2f velocidade;
	bool atacando;
	int dano;
	float alcance;
	bool podeAtacar;
	float duracaoCooldown;
	float timerCooldown;
	void setVelocidade(sf::Vector2f vel);
	sf::Vector2f getVelocidade();
	bool olhaDireita;

public:
	Personagem(sf::Vector2f pos, ID i);
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