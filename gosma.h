#pragma once
#include "entidade.h"

class Caracol;
class Gosma : public Entidades::Entidade {
private:
	int veneno;
	bool direita;

public:
	Gosma(sf::Vector2f pos, int veneno, bool direita);
	~Gosma();
	void inicializar();
	void executar();
	void colidir(Entidade* pEnt, float intersec_x, float intersec_y);
	virtual void efeito(Entidade* p);
};