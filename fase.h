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
#include "fundo.h"
#include <iostream>
using namespace std;

class Fase {
protected:
	Managers::Graphics* pGG;
//	Managers::Colisao *pC;
	ListaEntidades lista;
	Jogador j1;
public:
	Fase(Managers::Graphics* pG);
	~Fase();
	void criafundo();
	void criachao();
	void criaespinho();
	void criaagua();
	void atualizaView();
	void inicializar();
	void executar();
};
