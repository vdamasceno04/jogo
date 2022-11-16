#pragma once
#include "Obstaculo.h"

class Espinho :public Obstaculos::Obstaculo {
private:
public:
	Espinho(sf::Vector2f pos);
	~Espinho();
	void executar();
};
