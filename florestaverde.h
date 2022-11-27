#pragma once
#include"fase.h"
namespace Fases {
	class FlorestaVerde : public Fase {

	public:
		FlorestaVerde(bool doisJogadores, Managers::Graphics* pG, Managers::GerenciadorColisoes* pC);
		~FlorestaVerde();
		void criaagua();
		void criaabelhas();
		void inicializar();
		void executar();
		void colidir();

	};
}