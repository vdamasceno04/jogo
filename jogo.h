#pragma once
#include <SFML/Graphics.hpp>
#include"gerenciadorestados.h"
#include "florestaverde.h"
#include "florestavermelha.h"
#include "MenuPrincipal.h"
#include "MenuInterno.h"


using namespace Managers;

class Jogo
{
private:
	bool flagFase;
	int tela;
	ID i;
	Fases::FlorestaVerde fase1;
	Fases::FlorestaVermelha fase2;

	MenuPrincipal menuPrincipal;
	MenuInterno menuJogo;
  
	Managers::Graphics* pGG;
	GerenciadorColisoes* pGC;
	GerenciadorEstado* pGE;

public:
	Jogo();
	~Jogo();
	void inicializar();
	void executar();
};