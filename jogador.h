#pragma once
#include"inimigo.h"
#include <string>

#define VMAXX 1.0
#define VMAXY 0.5
class ListaEntidades;

class Jogador : public Personagem {
private:

public:
	Jogador(sf::Vector2f pos);
	~Jogador();
	virtual void executar() = 0;
	virtual void controlar() = 0;
	void ataca();

	virtual void colidir(Entidade* pEnt, ID id) { }
};