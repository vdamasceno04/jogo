#pragma once
#include"inimigo.h"
#include <string>

#define VMAXX 1.0
#define VMAXY 15.0	

class ListaEntidades;

class Jogador : public Personagem {
protected:
	bool pulando;
	bool podePular;
public:
	Jogador(sf::Vector2f pos);
	~Jogador();
	virtual void executar() = 0;
	virtual void controlar() = 0;
	void ataca();
	void colidir(Entidade* pEnt, float insersec_x, float intersec_y);
};