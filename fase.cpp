#include "Fase.h"

Fase::Fase(Managers::Graphics* pG) :
    listaEst(), j1(),  listaMov()
{
    pGG = pG;
    pGC = GerenciadorColisoes::getInstancia(&listaMov, &listaEst);
}

Fase::~Fase() {
  /*  int i;
    for(i=0; i<listaEst.getLen(); i++)
        delete listaEst.getItem(i);
    for (i = 0; i < listaMov.getLen(); i++)
        delete listaMov.getItem(i);*/
}

void Fase::criafundo(bool dia)
{
    int i;
    int pos = 0;
    Fundo* pAux;
    for (i = 0; i < 8; i++) {
        pAux = new Fundo(sf::Vector2f(pos, 0), dia);
        listaEst.addEntidade(pAux);
        pos += WIDTH - 2;
    }
}

void Fase::criaespinho() {
    int i;
    int sorteia;
    int pos = 800;
    Espinho* pAux;
    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        sorteia = rand() % 2;
        if (sorteia == 0 || i % 3 == 0) {
            pAux = new Espinho(sf::Vector2f(pos, HEIGHT * 0.835));
            listaEst.addEntidade(pAux);
        }
        pos += 500;
    }
}

void Fase::criajavali() {
    int i;
    int pos = WIDTH * 6 - WIDTH / 3;
    int idade;
    int sorteia;
    Javali* pAux;
    srand(time(NULL));
    for (i = 0; i < 6; i++) {
        sorteia = rand() % 2;
        if (sorteia == 0 || i % 2 == 0) {
            idade = (rand() % 8) + 2;
            pAux = new Javali(sf::Vector2f(pos, HEIGHT * 0.64), &j1, &e1, idade);
            listaMov.addEntidade(pAux);
        }
        pos += 220;
    }
}

void Fase::criachao(bool vermelho)
{
    int i;
    int pos = 0;
    Plataforma* pAux;
    for (i = 0; i < 121; i++) {
        pAux = new Plataforma(sf::Vector2f(pos, HEIGHT * 6 / 7), vermelho);
        listaEst.addEntidade(pAux);
        pos += 71;
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