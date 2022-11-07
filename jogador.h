#pragma once
#include"entidade.h"

class Jogador : public Entidades::Entidade{
private: 
public:
	Jogador();
	~Jogador();
	void move();
};