#include"florestavermelha.h"
#include<time.h>
#include<stdlib.h>

FlorestaVermelha::FlorestaVermelha(Managers::Graphics* pG) :
    Fase(pG) {
    pGG = pG;
}

FlorestaVermelha::~FlorestaVermelha() {}

void FlorestaVermelha::criaespinho() {
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

void FlorestaVermelha::criacaracol() {
    int i;
    int veneno;
    int pos = 600;
    int sorteia;
    Caracol* pCaracol;
    Gosma* pGosma;
    for (i = 0; i < 9; i++) {
        sorteia = rand() % 3;
        if (sorteia == 0 || i % 3 == 0) {
            veneno = rand() % 3 + 2;
            pGosma = new Gosma(sf::Vector2f(sf::Vector2f(pos + 40, (HEIGHT * 0.74) + 30)), veneno);
            pCaracol = new Caracol(sf::Vector2f(pos, HEIGHT * 0.74), &j1, &e1, veneno, pGosma);
            listaMov.addEntidade(pGosma);
            listaMov.addEntidade(pCaracol);

        }
        pos += 500;
    }
}

void FlorestaVermelha::inicializar() {
    criafundo(false);
    listaMov.addEntidade(&j1);
    if (get2jogadores())
        listaMov.addEntidade(&e1);
    criacaracol();
    criaespinho();
    criajavali();
    criachao(true);
    criapedra();
    listaEst.setJanela(pGG);
    listaMov.setJanela(pGG);
}

void FlorestaVermelha::executar() {
    atualizaView();
    listaEst.executarLista();
    listaMov.executarLista();
}

void FlorestaVermelha::colidir() {
    pGC->ColidirEstaticoMovel();
    pGC->ColidirMovelMovel();
}