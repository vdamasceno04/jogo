#pragma once
#include"personagem.h"
#include <string>

class Jogador : public Personagem{
private: 
public:
	Jogador(sf::Vector2f position = sf::Vector2f(0, HEIGHT*0.69), sf::Vector2f size = sf::Vector2f(64, 80),
		int v = 9, int d = 0, float dC = 0, float dA = 0);
	~Jogador();
	void executar();
	void move();
};
