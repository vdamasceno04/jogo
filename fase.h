#pragma once
//#include "Ente.h"
#include <SFML/Graphics.hpp>
#include "ListaEntidades.h"
#include "cacador.h"
#include "explorador.h"
#include "graphics.h"
#include "Espinho.h"
#include "Agua.h"
#include "plataforma.h"
#include "abelha.h"
#include "fundo.h"
#include "javali.h"
#include <iostream>
using namespace std;

class Fase {
protected:
	Managers::Graphics* pGG;
//	Managers::Colisao *pC;
	ListaEntidades lista;
	Cacador j1;
	Explorador e1;

public:
	Fase(Managers::Graphics* pG);
	~Fase();
	void criafundo();
	void criachao();
	void criaespinho();
	void criajavali();
	void criaagua();
	void criaabelhas();
	void atualizaView();
	void inicializar();
	void executar();
};
