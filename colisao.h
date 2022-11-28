#pragma once
#include "ListaEntidades.h"
using namespace Entidades;

namespace Gerenciadores {
	class GerenciadorColisoes
	{
	protected:
		GerenciadorColisoes(Listas::ListaEntidades* lEM, Listas::ListaEntidades* lEE);

	private:
		Listas::ListaEntidades* listaEntidadesMoveis;
		Listas::ListaEntidades* listaEntidadesEstaticas;

		static GerenciadorColisoes* instancia; //Singleton

	public:
		static GerenciadorColisoes* getInstancia(Listas::ListaEntidades* lEM, Listas::ListaEntidades* lEE);
		~GerenciadorColisoes();

		void ColidirEstaticoMovel();
		void ColidirMovelMovel();
		void setListaEntidades(Listas::ListaEntidades* lEM, Listas::ListaEntidades* lEE);
		void colidir(Entidade* p1, Entidade* p2, float intersec_x, float intersec_y);
		void resolverColisao(Entidade* p1, Entidade* p2, float intersec_x, float intersec_y);

	};
}