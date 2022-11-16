#include"florestaverde.h"

FlorestaVerde::FlorestaVerde(Managers::Graphics* pG) :
	Fase(pG) {
	pGG = pG;
}

FlorestaVerde::~FlorestaVerde(){}

void FlorestaVerde::criafundo()
{
    int i;
    int pos = 0;
    Fundo* pAux;
    for (i = 0; i < 15; i++) {
        pAux = new Fundo(sf::Vector2f(pos, 0));
        lista.addEntidade(pAux);
        pAux->setpGG(pGG);
        pos += WIDTH - 2;
    }
}

void FlorestaVerde::criachao()
{
    int i;
    int pos = 0;
    Plataforma* pAux;
    for (i = 0; i < 100; i++) {
        pAux = new Plataforma(sf::Vector2f(pos, HEIGHT * 6 / 7));
        lista.addEntidade(pAux);
        pAux->setpGG(pGG);
        pos += 71;
    }
}

void FlorestaVerde::criaespinho() {
    int i;
    int pos = 400;
    Espinho* pAux;
    for (i = 0; i < 15; i++) {
        pAux = new Espinho(sf::Vector2f(pos, HEIGHT * 0.835));
        lista.addEntidade(pAux);
        pAux->setpGG(pGG);
        pos += 300;
    }
}

void FlorestaVerde::criaagua() {
    int i;
    int pos = 200;
    Agua* pAux;
    for (i = 0; i < 15; i++) {
        pAux = new Agua(sf::Vector2f(pos, HEIGHT * 0.843));
        lista.addEntidade(pAux);
        pAux->setpGG(pGG);
        pos += 300;
    }

}

void FlorestaVerde::criajavali() {
    int i;
    int pos = 2000;
    Javali* pAux;
    for (i = 0; i < 1; i++) {
        pAux = new Javali(sf::Vector2f(pos, HEIGHT * 0.65), &j1, &e1);
        lista.addEntidade(pAux);
        pAux->setpGG(pGG);
        pos += 600;
    }
}
void FlorestaVerde::criaabelhas() {
    int i;
    int pos = 250;
    Abelha* pAux;
    for (i = 0; i < 1; i++) {
        pAux = new Abelha(sf::Vector2f(pos, HEIGHT * 0.65), &j1, &e1);
        lista.addEntidade(pAux);
        pAux->setpGG(pGG);
        pos += 600;
    }
}

void FlorestaVerde::inicializar() {
    criafundo();
    lista.addEntidade(&j1);
    j1.setpGG(pGG);
    lista.addEntidade(&e1);
    e1.setpGG(pGG);
    criaabelhas();
    criaespinho();
    criajavali();
    criachao();
    criaagua();
    lista.setJanela(pGG);
}

void FlorestaVerde::executar() {
    atualizaView();
    lista.executarLista();
}