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
	fundo = 10,
	pedra = 11,
	jogarfase1 = 12,
	jogarfase2 = 13
};



class Ente {
protected:
	ID id;
	static Managers::Graphics* pGG;
private:
	static int pontuacao;
public:
	Ente();
	static void setpGG(Managers::Graphics* p);
	ID getId();
	static void setPontos(int pontos);
	static int getPontuacao();
	int getPontos(ID id);
	~Ente();
	virtual void executar() = 0;
};