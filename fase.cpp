#include "Fase.h"

Fase::Fase(Managers::Graphics* pG) :
lista()
{
    pGG = pG;
}

Fase::~Fase() {}

void Fase::criafundo()
{
    int i;
    int pos = 0;
    Fundo* pAux;
    for (i = 0; i < 15; i++) {
        pAux = new Fundo(sf::Vector2f(pos, 0), sf::Vector2f(0,0));
        lista.addEntidade(pAux);
        pos += WIDTH-2;
    }
}
void Fase::criachao()
{
    int i;
    int pos = 0;
    Plataforma* pAux;
    for (i = 0; i < 100; i++) {
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

void Fase::criaabelhas() {

}

void Fase::atualizaView() {
    if (j1.getBody().getPosition().x >= pGG->getView().x)
        pGG->centerView(sf::Vector2f(j1.getBody().getPosition().x, HEIGHT/2));
}

void Fase::inicializar() {
    criafundo();
    lista.addEntidade(&j1);
    lista.addEntidade(&a1);
    criaespinho();
    criachao();
    criaagua();
    lista.setJanela(pGG);
}
void Fase::executar(){
    atualizaView();
//    cout << "j1posx" << j1.getBody().getPosition().x << endl;
//    cout << "w pos" << pGG->getView().x << endl;
    lista.executarLista();
}