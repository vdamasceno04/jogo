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
#include "gosma.h"
#include <iostream>


#include"pedra.h"

using namespace std;

class Fase {
private: 
	bool doisJogadores;
public:
	Managers::Graphics* pGG;
	GerenciadorColisoes* pGC;
	static ListaEntidades listaEst;
	static ListaEntidades listaMov;
	Cacador j1;
	Explorador e1;

	bool fimFase();
	void set2jogadores(bool jog) { doisJogadores = jog; }
	bool get2jogadores() { return doisJogadores; }

	Fase(Managers::Graphics* pgg, GerenciadorColisoes* pgc);
	~Fase();
	void atualizaView();
	void criafundo(bool dia);
	void criapedra();
	void criajavali();
	void criachao(bool vermelho);
	virtual void executar() = 0;
	virtual void colidir() = 0;
};