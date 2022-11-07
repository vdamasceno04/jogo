#include "jogo.h"

Jogo::Jogo()
{
    Executar();
}

Jogo::~Jogo() {}

void Jogo::Executar()

    while (pGG->isWindowOpen())
    {
        sf::Event event;
        while (pGG->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                pGG->closeWindow();
        }

        pGG->clear();
        pGG->display();
    }
        pGG->clear();
        pGG->display();
    }*/
}
