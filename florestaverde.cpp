#include"florestaverde.h"
#include<time.h>
#include<stdlib.h>

FlorestaVerde::FlorestaVerde(Managers::Graphics* pG, GerenciadorColisoes* pC) :
    Fase(pG, pC) {
    pGG = pG;
    pGC = pC;
}

FlorestaVerde::~FlorestaVerde() {

}

void FlorestaVerde::criaagua() {
    int i;
    int sorteia;
    int pos = 500;
    Agua* pAux;
    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        sorteia = rand() % 2;
        if (sorteia == 0 || i%2 == 0) {
            pAux = new Agua(sf::Vector2f(pos, HEIGHT * 0.856));
            listaEst.addEntidade(pAux);
        }
        pos += 500;
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
    criafundo(true);
    listaMov.addEntidade(&j1);
    if(get2jogadores())
        listaMov.addEntidade(&e1);
    criaabelhas();
    criapedra();
    criajavali();
    criachao(false);
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