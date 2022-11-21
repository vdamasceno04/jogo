#include"florestavermelha.h"
#include<time.h>
#include<stdlib.h>

FlorestaVermelha::FlorestaVermelha(Managers::Graphics* pG) :
    Fase(pG) {
    pGG = pG;
}

FlorestaVermelha::~FlorestaVermelha() {}

void FlorestaVermelha::criachao()
{
    int i;
    int pos = 0;
    Plataforma* pAux;
    for (i = 0; i < 121; i++) {
        pAux = new Plataforma(sf::Vector2f(pos, HEIGHT * 6 / 7), true);
        listaEst.addEntidade(pAux);
        pos += 71;
    }
}

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

void FlorestaVermelha::criajavali() {
    int i;
    int pos = WIDTH * 6 - WIDTH / 3;
    int idade;
    int sorteia;
    Javali* pAux;
    srand(time(NULL));
    for (i = 0; i < 6; i++) {
        sorteia = rand() % 2;
        if (sorteia == 0 || i % 2 == 0) {
            idade = (rand() % 8) + 3;
            pAux = new Javali(sf::Vector2f(pos, HEIGHT * 0.64), &j1, &e1, idade);
            listaMov.addEntidade(pAux);
        }
        pos += 220;
    }
}

void FlorestaVermelha::criacaracol() {
    int i;
    int veneno;
    int pos = 250;
    int sorteia;
    Caracol* pCaracol;
    Gosma* pGosma;
    for (i = 0; i < 13; i++) {
        sorteia = rand() % 2;
        if (sorteia == 0 || i % 3 == 0) {
            veneno = rand() % 3 + 2;
            pGosma = new Gosma(sf::Vector2f(sf::Vector2f(pos + 50, (HEIGHT * 0.60) + 85)), veneno);
            pCaracol = new Caracol(sf::Vector2f(pos, HEIGHT * 0.60), &j1, &e1, veneno, pGosma);
            listaMov.addEntidade(pGosma);
            listaMov.addEntidade(pCaracol);

        }
        pos += 400;
    }
}

void FlorestaVermelha::inicializar() {
    criafundo();
    listaMov.addEntidade(&j1);
    listaMov.addEntidade(&e1);
    criacaracol();
    criaespinho();
    criajavali();
    criachao();
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