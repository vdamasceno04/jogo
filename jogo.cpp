#include "jogo.h"
#include<stdio.h>

Jogo::Jogo() :
    pGG(Graphics::getInstance()),
    fase1(Graphics::getInstance()),
    fase2(Graphics::getInstance()),
    menuPrincipal()
{
    Ente::setpGG(Graphics::getInstance());
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

            //Executar Menus
            if (menuPrincipal.getAtivo() || menuPrincipal.getEscolhaAtivo() || menuPrincipal.getLeaderboardAtivo())
            {
                pGG->clear();
                menuPrincipal.executar();
                if (!flagFase)
                    flagFase = true;

                pGG->display();
            }
        }

        /*
        //Executar Menus
        if (menuPrincipal.getAtivo() || menuPrincipal.getEscolhaAtivo() || menuPrincipal.getLeaderboardAtivo())
        {
            pGG->clear();
            menuPrincipal.executar();
            if (!flagFase)
                flagFase = true;
            
            pGG->display();
        }*/

        //Executar Fase
        if (!menuPrincipal.getAtivo() && !menuPrincipal.getEscolhaAtivo() && !menuPrincipal.getLeaderboardAtivo())
        {
            int auxE = menuPrincipal.getEscolheu();
            pGG->clear();
            //Fase 1 com um jogador
            if (auxE == 1)
            {
                if (flagFase) {
                    fase1.inicializar();
                    //fase1.setDoisJogadores(false);
                }
                //if (fase1.fimFase())
                //    menuPrincipal.setAtivo(true);
                fase1.executar();
                fase1.colidir();
            }
            //Fase 1 com dois jogadores
            else if (auxE == 2)
            {
                if (flagFase) {
                    fase1.inicializar();
                    //fase1.setDoisJogadores(true);
                }
                //if (fase1.fimFase())
                //    menuPrincipal.setAtivo(true);
                fase1.executar();
                fase1.colidir();
            }

            //Fase 2 com um jogador
            else if (auxE == 3)
            {
                if (flagFase) {
                    fase2.inicializar();
                    //fase2.setDoisJogadores(false);
                }
                //if (fase2.fimFase())
                //    menuPrincipal.setAtivo(true);
                fase2.executar();
                fase2.colidir();
            }
            //Fase 2 com dois jogadores
            else if (auxE == 3)
            {
                if (flagFase) {
                    fase2.inicializar();
                    //fase2.setDoisJogadores(true);
                }
                //if (fase2.fimFase())
                //    menuPrincipal.setAtivo(true);
                fase2.executar();
                fase2.colidir();
            }
            else
                menuPrincipal.setAtivo(true);

            pGG->display();
        }

    }
}

/*
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
*/
