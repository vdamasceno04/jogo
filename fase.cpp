#include "Fase.h"

Fase::Fase(Managers::Graphics* pG) :
lista()
{
    pGG = pG;
    if (pGG == NULL)
        printf("abc");
    lista.addEntidade(&f);
    lista.addEntidade(&j1); 
    lista.addEntidade(&a1);
    lista.addEntidade(&e1);
}

Fase::~Fase() {}

void Fase::criachao()
{
    int i;
    int pos = 0;
    Plataforma* pAux;
    for (i = 0; i < 15; i++) {
        pAux = new Plataforma(sf::Vector2f(pos,HEIGHT-150), sf::Vector2f (500,50), 0, false, false, false);
        
        pos += 71;
        lista.addEntidade(pAux);
    }
}
void Fase::inicializar() {
    criachao();
    lista.setJanela(pGG);
    
}
void Fase::executar(){
    lista.executarLista();
}
