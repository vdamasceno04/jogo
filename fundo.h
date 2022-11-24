#pragma once
#include "entidade.h"

class Fundo : public Entidades::Entidade {
private:
	bool dia;
public:
	Fundo(sf::Vector2f pos, bool dia);
	~Fundo();
	void executar();
	void colidir(Entidade* pEnt, ID id) {}
};