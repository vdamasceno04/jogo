#pragma once
#include <SFML/Graphics.hpp>
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
  
	Fases::FlorestaVerde fase1;
	Fases::FlorestaVermelha fase2;

	MenuPrincipal menuPrincipal;
	MenuInterno menuJogo;
  
	Managers::Graphics* pGG;
	GerenciadorColisoes* pGC;

public:
	Jogo();
	~Jogo();
	void inicializar();
	void executar();
};