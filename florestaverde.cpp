#include"florestaverde.h"
#include<time.h>
#include<stdlib.h>

FlorestaVerde::FlorestaVerde(Managers::Graphics* pG) :
    Fase(pG) {
    pGG = pG;
}

FlorestaVerde::~FlorestaVerde() {}

void FlorestaVerde::criachao()
{
    int i;
    int pos = 0;
    Plataforma* pAux;
    for (i = 0; i < 121; i++) {
        pAux = new Plataforma(sf::Vector2f(pos, HEIGHT * 6 / 7), false);
        listaEst.addEntidade(pAux);
        pos += 71;
    }
}

void FlorestaVerde::criaespinho() {
    int i;
    int sorteia;
    int pos = 800;
    Espinho* pAux;
    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        sorteia = rand() % 2;
        if (sorteia == 0 || i%3 == 0) {
            pAux = new Espinho(sf::Vector2f(pos, HEIGHT * 0.835));
            listaEst.addEntidade(pAux);
        }
        pos += 500;
    }
}

void FlorestaVerde::criaagua() {
    int i;
    int sorteia;
    int pos = 500;
    Agua* pAux;
    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        sorteia = rand() % 2;
        if (sorteia == 0) {
            pAux = new Agua(sf::Vector2f(pos, HEIGHT * 0.856));
            listaEst.addEntidade(pAux);
        }
        pos += 500;
    }

}

void FlorestaVerde::criajavali() {
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

void FlorestaVerde::criaabelhas() {
    int i;
    int mel;
    int pos = 250;
    int sorteia;
    Abelha* pAux;
    for (i = 0; i < 13; i++) {
        sorteia = rand() % 2;
        if (sorteia == 0 || i%3 == 0) {
            mel = rand() % 3 + 2;
            pAux = new Abelha(sf::Vector2f(pos, HEIGHT * 0.69), &j1, &e1, mel);
            listaMov.addEntidade(pAux);
        }
        pos += 400;
    }
}

void FlorestaVerde::inicializar() {
    criafundo();
    listaMov.addEntidade(&j1);
    listaMov.addEntidade(&e1);
    criaabelhas();
    criaespinho();
    criajavali();
    criachao();
    criaagua();
    listaEst.setJanela(pGG);
    listaMov.setJanela(pGG);
}

void FlorestaVerde::executar() {
    atualizaView();
    listaEst.executarLista();
    listaMov.executarLista();
}

void FlorestaVerde::colidir() {
    pGC->ColidirEstaticoMovel();
    pGC->ColidirMovelMovel();
}