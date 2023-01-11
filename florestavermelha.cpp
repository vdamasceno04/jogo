#include"florestavermelha.h"
#include<time.h>
#include<stdlib.h>

Fases::FlorestaVermelha::FlorestaVermelha(bool doisJoga, Gerenciadores::Graficos* pG, Gerenciadores::GerenciadorColisoes* pC) :
    Fase(doisJoga, pG, pC) {
    pGG = pG;
    pGC = pC ;
    doisJogadores = doisJoga;
    id = fase2;
    inicializar();
}

Fases::FlorestaVermelha::~FlorestaVermelha() {}

void Fases::FlorestaVermelha::criaespinho() {
    int i;
    int sorteia;
    int pos = 800;
    Espinho* pAux;
    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        sorteia = rand() % 2;
        if (sorteia == 0 || i % 3 == 0) {
            pAux = new Espinho(Math::CoordF(pos, HEIGHT * 0.835));
            listaEst.addEntidade(pAux);
        }
        pos += 500;
    }
}

void Fases::FlorestaVermelha::criacaracol() {
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
            pGosma = new Gosma(Math::CoordF(Math::CoordF(pos + 40, (HEIGHT * 0.74) + 30)), veneno);
            pCaracol = new Caracol(Math::CoordF(pos, HEIGHT * 0.74), &j1, &e1, veneno, pGosma);
            listaMov.addEntidade(pGosma);
            listaMov.addEntidade(pCaracol);

        }
        pos += 500;
    }
}

void Fases::FlorestaVermelha::inicializar() {
    criafundo(false);
    listaMov.addEntidade(&j1);
    if (doisJogadores)
        listaMov.addEntidade(&e1);
    criacaracol();
    criaespinho();
    criajavali();
    criachao(true);
    criapedra();
    listaEst.setJanela(pGG);
    listaMov.setJanela(pGG);
}

void Fases::FlorestaVermelha::executar() {
    atualizaView();
    listaEst.executarLista();
    listaMov.executarLista();
    colidir();
    fimFase();
}

void Fases::FlorestaVermelha::colidir() {
    pGC->ColidirEstaticoMovel();
    pGC->ColidirMovelMovel();
}