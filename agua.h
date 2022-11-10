#pragma once
#include "Obstaculo.h"

class Agua : public Obstaculos::Obstaculo {
private:
public:
	Agua(sf::Vector2f pos = sf::Vector2f(300, 630), sf::Vector2f tam = sf::Vector2f(0, 0), int d = 0, float dC = 1, bool dan = true, bool l = false);
	~Agua();
	void executar();
};
