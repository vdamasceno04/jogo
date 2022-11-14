#pragma once
#include"inimigo.h"
#include <string>

class Jogador : public Personagem{
private: 
public:
	Jogador(sf::Vector2f position = sf::Vector2f(0, HEIGHT*0.69), sf::Vector2f size = sf::Vector2f(64, 80),
		int v = 7, int d = 0, float alc = 40, float dC = 0, float dA = 0);
	~Jogador();
	virtual void executar() = 0;
	virtual void move() = 0;
};
