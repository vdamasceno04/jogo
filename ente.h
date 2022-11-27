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
	fase1 = 12,
	fase2 = 13,
	jogar = 14,
	menuprincipal = 15,
	leaderboard = 16,
	menuescolha = 17,
	fase12jog = 22,
	fase22jog = 23
};



class Ente {
protected:
	ID id;
	static Managers::Graphics* pGG;
	int estado;
private:
	static int pontuacao;
public:
	Ente();
	static void setpGG(Managers::Graphics* p);
	ID getId();
	static void setPontos(int pontos);
	static int getPontuacao();
	int getPontos(ID id);
	int getEstado() {return estado;}
	void setEstado(int est) {estado = est;}
	~Ente();
	virtual void executar() = 0;
};