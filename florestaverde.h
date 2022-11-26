#pragma once
#include"fase.h"

class FlorestaVerde : public Fase {

public:
	FlorestaVerde(Managers::Graphics* pG, GerenciadorColisoes* pC);
	~FlorestaVerde();
	void criaagua();
	void criaabelhas();
	void inicializar();
	void executar();
	void colidir();

};