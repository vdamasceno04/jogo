#pragma once
#include"fase.h"

class FlorestaVermelha : public Fase {

public:
	FlorestaVermelha(Managers::Graphics* pG, GerenciadorColisoes* pC);
	~FlorestaVermelha();
	void criacaracol();
	void criaespinho();
	void inicializar();
	void executar();
	void colidir();
};