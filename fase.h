#pragma once
#include <SFML/Graphics.hpp>
#include "ListaEntidades.h"
#include "colisao.h"
#include "cacador.h"
#include "explorador.h"
#include "graphics.h"
#include "Espinho.h"
#include "Agua.h"
#include "plataforma.h"
#include "abelha.h"
#include "fundo.h"
#include "javali.h"
#include "caracol.h"
#include <iostream>
using namespace std;

class Fase {
public:

	Managers::Graphics* pGG;
	GerenciadorColisoes* pGC;
	ListaEntidades listaEst;
	ListaEntidades listaMov;
	Cacador j1;
	Explorador e1;

	Fase(Managers::Graphics* pG);
	~Fase();
	void atualizaView();
	void criafundo();
	virtual void executar() = 0;
	virtual void colidir() = 0;
};