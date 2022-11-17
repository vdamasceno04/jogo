#include "Fase.h"

Fase::Fase(Managers::Graphics* pG) :
    listaEst(), j1(), e1(), listaMov()
{
    pGG = pG;
    pGC = GerenciadorColisoes::getInstancia(&listaMov, &listaEst);
}

Fase::~Fase() {}

void Fase::criafundo()
{
    int i;
    int pos = 0;
    Fundo* pAux;
    for (i = 0; i < 8; i++) {
        pAux = new Fundo(sf::Vector2f(pos, 0));
        listaEst.addEntidade(pAux);
        pAux->setpGG(pGG);
        pos += WIDTH - 2;
    }
}

void Fase::atualizaView() {
    if (j1.getBody().getPosition().x >= pGG->getView().x)
        pGG->centerView(sf::Vector2f(j1.getBody().getPosition().x, HEIGHT / 2));
    if (e1.getBody().getPosition().x >= pGG->getView().x)
        pGG->centerView(sf::Vector2f(e1.getBody().getPosition().x, HEIGHT / 2));
    if (j1.getBody().getPosition().x >= (WIDTH * 8 - WIDTH / 2) || e1.getBody().getPosition().x >= (WIDTH * 8 - WIDTH / 2))
        pGG->centerView(sf::Vector2f(WIDTH * 8 - WIDTH / 1.9, HEIGHT / 2));
}