#pragma once
#include "inimigo.h"
#include "gosma.h"

class Caracol : public Inimigo {
private:
	int veneno;
	Gosma* gosma;
	bool cuspir;
public:
	Caracol(sf::Vector2f pos, Jogador* p1, Jogador* p2, int ven, Gosma* pGosma);
	~Caracol();
	void inicializa(int ven);
	void executar();
	bool getCuspir();
	void ataca(Jogador* pJ);
};