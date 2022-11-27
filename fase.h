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

namespace Fases {
	class Fase : public Ente {
	protected:
		bool doisJogadores;
	public:
		Managers::Graphics* pGG;
		Managers::GerenciadorColisoes* pGC;
		static Listas::ListaEntidades listaEst;
		static Listas::ListaEntidades listaMov;
		Cacador j1;
		Explorador e1;

		bool fimFase();
		void set2jogadores(bool jog) { doisJogadores = jog; }
		bool get2jogadores() { return doisJogadores; }

		Fase(Managers::Graphics* pgg, Managers::GerenciadorColisoes* pgc);
		~Fase();
		void atualizaView();
		void criafundo(bool dia);
		void criapedra();
		void criajavali();
		void criachao(bool vermelho);
		void finaliza();
		virtual void executar() = 0;
		virtual void colidir() = 0;
	};
}