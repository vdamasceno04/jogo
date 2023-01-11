#pragma once
#include "entidade.h"

class Caracol;
class Gosma : public Entidades::Entidade {
private:
	int veneno;
	Caracol* pCaracol;
public:
	Gosma(Math::CoordF pos, int veneno);
	~Gosma();
	void setCaracol(Caracol* pCar);
	void inicializar();
	void executar();
	void efeito(Entidade* p);
};