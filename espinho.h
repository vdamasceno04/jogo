#pragma once
#include "Obstaculo.h"

class Espinho :public Obstaculos::Obstaculo {
private:
	bool danificar;
	float duracaoCooldown;
	float timerCooldown;

public:
	Espinho(Math::CoordF pos);
	~Espinho();
	bool  getDanificar();
	void atualizaDanificar();
	float getCooldown();
	void contaTempoCooldown(const float dt);
	void efeito(Entidade* p);
	void executar();
};
