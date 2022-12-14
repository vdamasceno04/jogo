#include "ListaEntidades.h"
using namespace Listas;


ListaEntidades::ListaEntidades():objLE(){
    /*for (int i = 0; i < objLE.getLen(); i++) {

        this->removeEntidade(objLE.getItem(i));
    }*/
}

ListaEntidades::~ListaEntidades(){}

void ListaEntidades::addEntidade(Entidades::Entidade* entidade) { objLE.push(entidade); }

void ListaEntidades::removeEntidade(Entidades::Entidade* entidade) {
    objLE.pop(entidade);
}

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
        pAux->setJanela(pGG->getWindow());
    }
}

void ListaEntidades::limpaLista() {
    for (int i = 0; i < objLE.getLen(); i++) {
        removeEntidade(objLE.getItem(i));
        cout << "limpa";
    }
    cout << "limpo" << endl << endl;
}

void ListaEntidades::executarLista()
{
    Entidades::Entidade* pAux;

    for (int i = 0; i < objLE.getLen(); i++) {
        pAux = objLE.getItem(i);

        if (pAux->getRemove()) {
            Ente::setPontos(pAux->getPontos(pAux->getId()));
            removeEntidade(pAux);
            //DESTRUIR
        }
        pAux->executar();
    }
}