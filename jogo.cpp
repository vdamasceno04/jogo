#include "jogo.h"
#include<stdio.h>

Jogo::Jogo():
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
    printf("a");
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
        pGG->display();
    }
}




















/*






//FUNCIONANDO
void Jogo::inicializar() {
    j1.setWindow(pGG->getWindow());
    e1.setWindow(pGG->getWindow());
    p1.setWindow(pGG->getWindow());
    a1.setWindow(pGG->getWindow());
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
        j1.executar();
        a1.executar();
        e1.executar();
        p1.executar();
        pGG->display();
       }

}
*/