#pragma once
#include "ListaEntidades.h"

class GerenciadorColisoes
{
protected:
	GerenciadorColisoes(ListaEntidades* lEM, ListaEntidades* lEE);

private:
	ListaEntidades* listaEntidadesMoveis;
	ListaEntidades* listaEntidadesEstaticas;

	static GerenciadorColisoes* instancia; //Singleton

public:
	static GerenciadorColisoes* getInstancia(ListaEntidades* lEM, ListaEntidades* lEE);
	~GerenciadorColisoes();

	void ColidirEstaticoMovel();
	void ColidirMovelMovel();
	void setListaEntidades(ListaEntidades* lEM, ListaEntidades* lEE);
	//void clear();

};