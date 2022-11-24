#pragma once
#include "Obstaculo.h"

class Pedra : public Obstaculos::Obstaculo {
private:
public:
	Pedra(sf::Vector2f pos);
	~Pedra();
	void executar();
	virtual void efeito(Entidade* p) {};
};
