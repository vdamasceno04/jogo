#pragma once
#include"inimigo.h"
#include <string>

class ListaEntidades;

class Jogador : public Personagem {
protected:
public:
	Jogador(Math::CoordF pos);
	~Jogador();
	virtual void executar() = 0;
	virtual void controlar() = 0;
	void ataca();
};