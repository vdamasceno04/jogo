#pragma once
#include "entidade.h"

class Fundo: public Entidades::Entidade {
private:
public:
	Fundo(sf::Vector2f pos);
	~Fundo();
	void executar();
};