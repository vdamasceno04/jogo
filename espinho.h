#pragma once
#include "Obstaculo.h"

class Espinho :public Obstaculos::Obstaculo {
private:
	int dano;

public:
	Espinho(sf::Vector2f pos, ID i = ID::espinho);
	~Espinho();
	void ferir();
	void executar();
};
