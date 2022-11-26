#pragma once
#include "ListaEntidades.h"
using namespace Entidades;

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
	void colidir(Entidade* p1, Entidade* p2, float intersec_x, float intersec_y);
	void resolverColisao(Entidade* p1, Entidade* p2, float intersec_x, float intersec_y);
	//void clear();

};