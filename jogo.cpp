#include "jogo.h"
#include<stdio.h>

Jogo::Jogo():
pGG(Graphics::getInstance()) 
{
    executar();
}

Jogo::~Jogo() {}

void Jogo::inicializar() {
    j1.setWindow(pGG->getWindow());
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
        pGG->display();
       }

}
