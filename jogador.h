#pragma once
#include"entidade.h"

class Jogador : public Entities::Entidade{
private: 
public:
	Jogador();
	~Jogador();
	void move();
};