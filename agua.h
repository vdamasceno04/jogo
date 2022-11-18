#pragma once
#include "Obstaculo.h"

class Agua : public Obstaculos::Obstaculo {
private:
public:
	Agua(sf::Vector2f pos);
	~Agua();
	void executar();
};
