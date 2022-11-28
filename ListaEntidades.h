#pragma once
#include "Lista.h"
#include "entidade.h"

namespace Listas {
	class ListaEntidades {
	private:
		Lista<Entidades::Entidade> objLE;

	public:
		ListaEntidades();
		~ListaEntidades();
		void addEntidade(Entidades::Entidade* entidade);
		void removeEntidade(Entidades::Entidade* entidade);
		int getLen();
		Entidades::Entidade* getItem(int i);
		void setJanela(Gerenciadores::Graficos* pGG);
		void executarLista();
		void limpaLista();
	};
}