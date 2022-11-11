#pragma once
#include "entidade.h"
#define WIDTH 1080
#define HEIGHT 720

class Fundo: public Entidades::Entidade {
private:
public:
	Fundo(sf::Vector2f pos = sf::Vector2f(0,0), sf::Vector2f tam = sf::Vector2f(0, 0));
	~Fundo();
	void executar();
};