#include "Fase.h"

Fase::Fase(Managers::Graphics* pG) :
lista()
{
    pGG = pG;
    lista.addEntidade(&j1); //PROBLEMA AQUI
  /*  lista.addEntidade(&a1);
    lista.addEntidade(&e1);
    lista.addEntidade(&p1);*/
}

Fase::~Fase() {}

void Fase::executar(){
    executarLista(); 
}

void Fase::setJanela()
{                                           //Atribui janela para cada entidade
    Entidades::Entidade* pAux;

    for (int i = 0; i < lista.getLen(); i++) {
        pAux = lista.getItem(i);
        pAux->setWindow(pGG->getWindow());
    }
}

void Fase::executarLista()
{
    Entidades::Entidade* pAux;

    for (int i = 0; i < lista.getLen(); i++) {
        pAux = lista.getItem(i);
        printf("caiu");
        pAux->executar(); 
    }
}