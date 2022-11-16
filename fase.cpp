#include "Fase.h"

Fase::Fase(Managers::Graphics* pG) :
lista(), j1(), e1()
{
    pGG = pG;
}

Fase::~Fase() {}
 
void Fase::atualizaView() {
    if (j1.getBody().getPosition().x >= pGG->getView().x)
        pGG->centerView(sf::Vector2f(j1.getBody().getPosition().x, HEIGHT/2));
    if (e1.getBody().getPosition().x >= pGG->getView().x)
        pGG->centerView(sf::Vector2f(e1.getBody().getPosition().x, HEIGHT / 2));
}