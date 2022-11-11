#include "ListaEntidades.h"

ListaEntidades::ListaEntidades():objLE(){}

ListaEntidades::~ListaEntidades(){}

void ListaEntidades::addEntidade(Entidades::Entidade* entidade) { objLE.push(entidade); }

void ListaEntidades::removeEntidade(Entidades::Entidade* entidade) { objLE.pop(entidade);}

int ListaEntidades::getLen() { return objLE.getLen(); }

Entidades::Entidade* ListaEntidades::getItem(int i)
{
    Entidades::Entidade* pAux;
    pAux = objLE.getItem(i);
    return pAux;
}

void ListaEntidades::setJanela(Managers::Graphics* pGG)
{                                           //Atribui janela para cada entidade
    Entidades::Entidade* pAux;

    for (int i = 0; i < objLE.getLen(); i++) {
        pAux = objLE.getItem(i);
        pAux->setWindow(pGG->getWindow());
    }
}


void ListaEntidades::executarLista()
{
    Entidades::Entidade* pAux;

    for (int i = 0; i < objLE.getLen(); i++) {
        pAux = objLE.getItem(i);
        pAux->executar();
    }
}