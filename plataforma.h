#pragma once
#include "Obstaculo.h"

class Plataforma : public Obstaculos::Obstaculo {
private:
public:
	Plataforma(sf::Vector2f pos);
	~Plataforma();
	void executar();
};


//Chão