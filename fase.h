#pragma once
//#include "Ente.h"
#include <SFML/Graphics.hpp>
#include "ListaEntidades.h"
#include "inimigo.h"
#include "jogador.h"
#include "graphics.h"
#include "Espinho.h"
#include "Agua.h"
#include "plataforma.h"

#include <iostream>
using namespace std;

class Fase { // public:Ente 
protected:
	Managers::Graphics* pGG;
	//Managers::Colision ? *pC;
	ListaEntidades lista;
	Jogador j1;
	Agua a1;
	Espinho e1;
	Plataforma p1;

public:
	Fase(Managers::Graphics* pG);
	~Fase();
	void setJanela();
	void executarLista();
	void executar();
};
