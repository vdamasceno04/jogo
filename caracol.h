#pragma once
#include "inimigo.h"

class Caracol : public Inimigo {
private:
	int veneno;
public:
	Caracol(sf::Vector2f pos, Jogador* p1, Jogador* p2, int ven);
	~Caracol();
	void inicializa(int mel);
	void ataca(Jogador* pJ);
	void executar();
	void cuspir(Jogador* pJ);
	void colidir(Entidade* pEnt, float insersec_x, float intersec_y);
};