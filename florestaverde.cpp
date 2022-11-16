#include"florestaverde.h"
#include<time.h>
#include<stdlib.h>

FlorestaVerde::FlorestaVerde(Managers::Graphics* pG) :
	Fase(pG) {
	pGG = pG;
}

FlorestaVerde::~FlorestaVerde(){}

void FlorestaVerde::criachao()
{
    int i;
    int pos = 0;
    Plataforma* pAux;
    for (i = 0; i < 121; i++) {
        pAux = new Plataforma(sf::Vector2f(pos, HEIGHT * 6 / 7));
        lista.addEntidade(pAux);
        pAux->setpGG(pGG);
        pos += 71;
    }
}

void FlorestaVerde::criaespinho() {
    int i;
    int sorteia;
    int pos = 800;
    Espinho* pAux;
    srand(time(NULL));
    for (i = 0; i < 20; i++) {
        sorteia = rand() % 2;
        if (sorteia == 0) {
            pAux = new Espinho(sf::Vector2f(pos, HEIGHT * 0.835));
            lista.addEntidade(pAux);
            pAux->setpGG(pGG);
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
    for (i = 0; i < 25; i++) {
        sorteia = rand() % 2;
        if (sorteia == 0) {
            pAux = new Agua(sf::Vector2f(pos, HEIGHT * 0.843));
            lista.addEntidade(pAux);
            pAux->setpGG(pGG);
        }
        pos += 500;
    }

}

void FlorestaVerde::criajavali() {
    int i;
    int pos = WIDTH * 8 - WIDTH / 3;
    int vida;
    int dano;
    int visao;
    Javali* pAux;
    srand(time(NULL));
    for (i = 0; i < 1; i++) {
        vida = (rand() % 8) + 10;
        dano = (rand() % 3) + 4;
        visao = (rand() % 100) + 600;
        pAux = new Javali(sf::Vector2f(pos, HEIGHT * 0.69), &j1, &e1, vida, dano, visao);
        cout << vida << endl;
        lista.addEntidade(pAux);
        pAux->setpGG(pGG);
    }
}

void FlorestaVerde::criaabelhas() {
    int i;
    int vida;
    int dano;
    int pos = 250;
    int sorteia;
    Abelha* pAux;
    for (i = 0; i < 10; i++) {
        vida = (rand() % 3) + 2;
        dano = (rand() % 2) + 1;
        sorteia = rand() % 2;
        if (sorteia == 0) {
            pAux = new Abelha(sf::Vector2f(pos, HEIGHT * 0.65), &j1, &e1, vida, dano);
            lista.addEntidade(pAux);
            pAux->setpGG(pGG);
        }
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