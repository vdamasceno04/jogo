#pragma once
#include "entidade.h"

class Fundo: public Entidades::Entidade {
private:
public:
	Fundo(sf::Vector2f pos, sf::Vector2f tam);
	~Fundo();
	void executar();
};