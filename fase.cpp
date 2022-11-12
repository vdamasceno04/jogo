#include "Fase.h"

Fase::Fase(Managers::Graphics* pG) :
lista()
{
    pGG = pG;
    lista.addEntidade(&f);
    lista.addEntidade(&j1); 
}

Fase::~Fase() {}

void Fase::criachao()
{
    int i;
    int pos = 0;
    Plataforma* pAux;
    for (i = 0; i < 15; i++) {
        pAux = new Plataforma(sf::Vector2f(pos, HEIGHT * 6 / 7));
        lista.addEntidade(pAux);
        pos += 71;
    }
}

void Fase::criaespinho() {
    int i;
    int pos = 400;
    Espinho* pAux;
    for (i = 0; i < 15; i++) {
        pAux = new Espinho(sf::Vector2f(pos, HEIGHT * 0.835));
        lista.addEntidade(pAux);
        pos += 300;
    }
}

void Fase::criaagua() {
    int i;
    int pos = 200;
    Agua* pAux;
    for (i = 0; i < 15; i++) {
        pAux = new Agua(sf::Vector2f(pos, HEIGHT*0.845));
        lista.addEntidade(pAux);
        pos += 300;
    }

}
void Fase::inicializar() {
    criaespinho();
    criachao();
    criaagua();

    lista.setJanela(pGG);
    
}
void Fase::executar(){
    lista.executarLista();
}
