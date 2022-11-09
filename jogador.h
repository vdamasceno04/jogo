#pragma once
#include"personagem.h"


class Jogador : public Personagem{
private: 
public:
	Jogador(Math::CoordF position = Math::CoordF(0.f, 0.f), Math::CoordF size = Math::CoordF(0.f, 0.f), 
		int v = 9, int d = 0, float dC = 0, float dA = 0);
	~Jogador();
	void executar();
	void move();
};
