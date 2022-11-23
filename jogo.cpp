#include "jogo.h"
#include<stdio.h>

Jogo::Jogo() :
    pGG(Graphics::getInstance()),
    fase1(Graphics::getInstance()),
    fase2(Graphics::getInstance()),
    menuPrincipal()
{
    Ente::setpGG(Graphics::getInstance());
    tela = 0;
    flagFase = true;
    executar();
}

Jogo::~Jogo() {
    Managers::Graphics::apagarInstance();
}
#include "jogo.h"
#include<stdio.h>

void Jogo::inicializar() {
    menuPrincipal.setValores();
}

void Jogo::executar()
{
    inicializar();
    sf::Event event;
    while (pGG->isWindowOpen())
    {
        while (pGG->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                pGG->closeWindow();

            //Menu
            if (tela == 0)
            {
                pGG->clear();
                menuPrincipal.executar();
                if (!flagFase)
                    flagFase = true;
                tela = menuPrincipal.getTela();
                pGG->display();
            }
        }
        //Fase 1 (era pra ser com um jogador mas tem 2)
        if (tela == 1)
        {
            pGG->clear();
            if (flagFase) {
                fase1.inicializar();
                flagFase = false;
            }
            fase1.executar();
            fase1.colidir();
            pGG->display();
        }
        //Fase 1 (dois jogadores)
        else if (tela == 2)
        {
            pGG->clear();
            if (flagFase) {
                fase1.inicializar();
                flagFase = false;
            }
            fase1.executar();
            fase1.colidir();
            pGG->display();
        }
        //Fase 2 (era pra ser com um jogador mas tem 2)
        else if (tela == 3)
        {
            pGG->clear();
            if (flagFase) {
                fase2.inicializar();
                flagFase = false;
            }
            fase2.executar();
            fase2.colidir();
            pGG->display();
        }
        //Fase 2 (dois jogadores)
        else if (tela == 4)
        {
            pGG->clear();
            if (flagFase) {
                fase2.inicializar();
                flagFase = false;
            }
            fase2.executar();
            fase2.colidir();
            pGG->display();
        }

    }
}