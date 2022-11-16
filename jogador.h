#pragma once
#include"inimigo.h"
#include <string>

class Jogador : public Personagem{
private: 
public:
	Jogador(sf::Vector2f pos, ID i);
	~Jogador();
	virtual void executar() = 0;
	virtual void move() = 0;
};
