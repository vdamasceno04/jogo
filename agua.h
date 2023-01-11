#pragma once
#include "Obstaculo.h"

class Agua : public Obstaculos::Obstaculo {
private:
	float lentidao;

public:
	Agua(Math::CoordF pos);
	~Agua();
	float getLentidao();
	void efeito(Entidade* p);
	void executar();
};
