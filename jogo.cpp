#include "jogo.h"
#include<stdio.h>

Jogo::Jogo() :
    pGG(Graphics::getInstance()),
 //   fase1(Graphics::getInstance())//,
    fase2(Graphics::getInstance())
{
    Ente::setpGG(Graphics::getInstance());
    executar();
}

Jogo::~Jogo() {
    Managers::Graphics::apagarInstance();
}
#include "jogo.h"
#include<stdio.h>

void Jogo::inicializar() {
 //   fase1.inicializar();
    fase2.inicializar();
}

void Jogo::executar()
{
    inicializar();
    while (pGG->isWindowOpen())
    {
        sf::Event event;
        while (pGG->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                pGG->closeWindow();
        }
        pGG->clear();
        fase2.executar();
        fase2.colidir();

        pGG->display();
    }
}