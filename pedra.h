#pragma once
#include "Obstaculo.h"

class Pedra : public Obstaculos::Obstaculo {
private:
public:
	Pedra(Math::CoordF pos);
	~Pedra();
	void executar();
	virtual void efeito(Entidade* p) {};
};
