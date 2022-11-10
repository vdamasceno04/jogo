#include "Fase.h"

Fase::Fase(Managers::Graphics* pG) :
    lista()
{
    pGG = pG;
}

Fase::~Fase() {}

void Fase::setJanela() // Como se fosse o inicializar 
{
    Entidades::Entidade* pAux;
    for (int i = 0; i < lista.getLen(); i++) {
        pAux = lista.getItem(i);
        pAux->setWindow(pGG->getWindow());
    }
}

void Fase::executarLista()
{
    while (pGG->isWindowOpen())
    {
        sf::Event event;
        while (pGG->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                pGG->closeWindow();
        }

        pGG->clear();

        Entidades::Entidade* pAux;
        for (int i = 0; i < lista.getLen(); i++) {
            pAux = lista.getItem(i);
            pAux->executar();
        }

        pGG->display();
    }
    
    Entidades::Entidade* pAux;
    for (int i = 0; i < lista.getLen(); i++) {
        pAux = lista.getItem(i);
        pAux->executar();
    }
}
