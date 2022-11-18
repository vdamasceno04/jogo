#pragma once
#include "coords.h"
#include "graphics.h"
#include<iostream>
using std::cout;
using std::endl;

enum ID {
	vazio = -1,
	cacador = 1,
	explorador = 2,
	plataforma = 3,
	agua = 4,
	espinho = 5,
	abelha = 6,
	javali = 7,
	caracol = 8,
	gosma = 9,
	fundo = 10
};



class Ente {
protected:
	ID id;
	Managers::Graphics* pGG;
public:
	Ente();
	void setpGG(Managers::Graphics* p) {pGG = p;}
	ID getId();
	~Ente();
	virtual void executar() = 0;
};