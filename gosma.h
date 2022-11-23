#pragma once
#include "entidade.h"

class Caracol;
class Gosma : public Entidades::Entidade {
private:
	int veneno;
	Caracol* pCaracol;
public:
	Gosma(sf::Vector2f pos, int veneno);
	~Gosma();
	void setCaracol(Caracol* pCar);
	void inicializar();
	void executar();
	void colidir(Entidade* pEnt, float intersec_x, float intersec_y);
	void efeito(Entidade* p);
};