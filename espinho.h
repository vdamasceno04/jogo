#pragma once
#include "Obstaculo.h"

class Espinho :public Obstaculos::Obstaculo {
private:
public:
	Espinho(sf::Vector2f pos = sf::Vector2f(500, 630), sf::Vector2f tam = sf::Vector2f(0, 0), int d = 0, float dC = 1, bool dan = true, bool l = false);
	~Espinho();
	void executar();
};
