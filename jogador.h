#pragma once
#include"inimigo.h"
#include <string>

class Jogador : public Personagem{
private: 
public:
	Jogador(sf::Vector2f pos);
	~Jogador();
	virtual void executar() = 0;
	virtual void move() = 0;
};
