 #pragma once
#include "Obstaculo.h"

class Plataforma : public Obstaculos::Obstaculo {
private:
	bool vermelho;
public:
	Plataforma(Math::CoordF pos, bool verm);
	~Plataforma();
	void executar();
	virtual void efeito(Entidade* p) {};
};
