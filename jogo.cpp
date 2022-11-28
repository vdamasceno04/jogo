#include "jogo.h"
#include<stdio.h>


using std::ofstream;
using std::string;
using std::cerr;
using std::fstream;

using namespace Fases;
Jogo::Jogo() :
    pGG(Graficos::getInstance()), pGC(GerenciadorColisoes::getInstancia(&Fase::listaMov, &Fase::listaEst)),
    pGE(GerenciadorEstado::getInstancia()) //singletons
{
    Ente::setpGG(Graficos::getInstance());

    pGE->addEstado(menuprincipal);
    executar();
}

Jogo::~Jogo() {
    Graficos::apagarInstance();
}

void Jogo::executar() {
    
    sf::Event event;
    while (pGG->isWindowOpen())
    {
        while (pGG->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                pGG->closeWindow();
        }
        if (pGE->tamanhoPilha() != 0)
            pGE->executar();
        else
            pGG->closeWindow();
        pGG->display();
    }
}