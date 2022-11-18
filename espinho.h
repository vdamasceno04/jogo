#pragma once
#include "Obstaculo.h"

class Espinho :public Obstaculos::Obstaculo {
private:
	int dano;
	bool danificar;
	float duracaoCooldown;
	float timerCooldown;

public:
	Espinho(sf::Vector2f pos);
	~Espinho();
	bool  getDanificar();
	int   getDano();
	void atualizaDanificar();
	float getCooldown();
	void contaTempoCooldown(const float dt);
	void efeito(Personagem* p);
	void executar();
};
