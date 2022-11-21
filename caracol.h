#pragma once
#include "inimigo.h"
#include "gosma.h"

class Caracol : public Inimigo {
private:
	int veneno;
	Gosma* gosma;
public:
	Caracol(sf::Vector2f pos, Jogador* p1, Jogador* p2, int ven);
	~Caracol();
	void inicializa(int mel);
	void executar();
	void mirar();
	void cuspir();
	void colidir(Entidade* pEnt, float insersec_x, float intersec_y);
};