#pragma once
#include "Obstaculo.h"

class Plataforma : public Obstaculos::Obstaculo {
private:
public:
	Plataforma(sf::Vector2f pos = sf::Vector2f(300, 630), sf::Vector2f tam = sf::Vector2f(0, 0), int d = 0, float dC = 1, bool dan = true, bool l = false);
	~Plataforma();
	void executar();
};


//Chão