#pragma once
#include "entidade.h"

class Fundo : public Entidades::Entidade {
private:
public:
	Fundo(sf::Vector2f pos, ID i = ID::fundo);
	~Fundo();
	void executar();
	void colidir(Entidade* pEnt, ID id) {}
};