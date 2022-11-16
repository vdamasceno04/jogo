#pragma once
#include "Obstaculo.h"

class Plataforma : public Obstaculos::Obstaculo {
private:
public:
	Plataforma(sf::Vector2f pos, ID i = ID::plataforma);
	~Plataforma();
	void executar();
};


//Chão