#include "jogo.h"

Jogo::Jogo() :
    window(sf::VideoMode(400, 400), "Jogo")
{
    jogador1.setWindow(&window);
    inimigo1.setWindow(&window);
    Executar();
}

Jogo::~Jogo() {}

void Jogo::Executar()
{
<<<<<<< Updated upstream
    while (window.isOpen())
=======
    while (pGG->isWindowOpen())
>>>>>>> Stashed changes
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

<<<<<<< Updated upstream
        jogador1.move();
        window.clear();
        jogador1.draw();
        inimigo1.draw();
        window.display();
=======
        pGG->clear();
        pGG->display();
>>>>>>> Stashed changes
    }
}
