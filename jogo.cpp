#include "jogo.h"
#include<stdio.h>

Jogo::Jogo() :
    pGG(Graphics::getInstance()),
    fase1(Graphics::getInstance())
{
    executar();
}

Jogo::~Jogo() {}
#include "jogo.h"
#include<stdio.h>

void Jogo::inicializar() {
    fase1.inicializar();
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
        fase1.executar();
        fase1.colidir();

        pGG->display();
    }
}