#include "colisao.h"

GerenciadorColisoes* GerenciadorColisoes::instancia = NULL;

GerenciadorColisoes::GerenciadorColisoes(ListaEntidades* lEM, ListaEntidades* lEE)
{
    listaEntidadesMoveis = lEM;
    listaEntidadesEstaticas = lEE;
}

GerenciadorColisoes* GerenciadorColisoes::getInstancia(ListaEntidades* lEM, ListaEntidades* lEE)
{
    if (instancia == 0) {
        instancia = new GerenciadorColisoes(lEM, lEE);
    }
    return instancia;
}

GerenciadorColisoes::~GerenciadorColisoes()
{
    listaEntidadesMoveis = nullptr;
    listaEntidadesEstaticas = nullptr;
}

void GerenciadorColisoes::ColidirEstaticoMovel()
{
    Entidades::Entidade* pAux1;
    Entidades::Entidade* pAux2;
    float intersec_x, intersec_y, dcentros_x, dcentros_y, dx, dy;
    int i, j;

    //Colisão entre Entidades Moveis e Estaticas
    for (i = 0; i < listaEntidadesEstaticas->getLen(); i++)
    {
        for (j = 0; j < listaEntidadesMoveis->getLen(); j++)
        {
            pAux1 = listaEntidadesEstaticas->getItem(i);
            pAux2 = listaEntidadesMoveis->getItem(j);

            if (pAux1->getPosicao().y > pAux2->getPosicao().y) {
                dy = abs(pAux2->getPosicao().y - pAux1->getPosicao().y);
                intersec_y = pAux2->getTamanho().y - dy;
            }
            else {
                dcentros_y = pAux1->getTamanho().y;
                dy = abs(pAux1->getPosicao().y - pAux2->getPosicao().y);
                intersec_y = dcentros_y - dy;
            }

            if (pAux1->getPosicao().x > pAux2->getPosicao().x) {
                dx = abs(pAux2->getPosicao().x - pAux1->getPosicao().x);
                intersec_x = pAux2->getTamanho().x - dx;
            }
            else {
                dcentros_x = pAux1->getTamanho().x;
                dx = abs(pAux1->getPosicao().x - pAux2->getPosicao().x);
                intersec_x = dcentros_x - dx;
            }

            if (intersec_x > 0.0 && intersec_y > 0.0) {
                pAux2->colidir(pAux1, intersec_x, intersec_y);
            }
        }
    }
}

void GerenciadorColisoes::ColidirMovelMovel(){
    //Colisão entre Entidades Moveis
    Entidades::Entidade* pAux1;
    Entidades::Entidade* pAux2;
    float intersec_x, intersec_y, dcentros_x, dcentros_y, dx, dy;
    int i, j;

    for (i = 0; i < listaEntidadesMoveis->getLen(); i++)
    {
        for (j = i+1; j < listaEntidadesMoveis->getLen(); j++)
        {
            pAux1 = listaEntidadesMoveis->getItem(i);
            pAux2 = listaEntidadesMoveis->getItem(j);

            if (pAux1->getPosicao().y > pAux2->getPosicao().y) {
                dy = abs(pAux2->getPosicao().y - pAux1->getPosicao().y);
                intersec_y = pAux2->getTamanho().y - dy;
            }
            else {
                dcentros_y = pAux1->getTamanho().y;
                dy = abs(pAux1->getPosicao().y - pAux2->getPosicao().y);
                intersec_y = dcentros_y - dy;
            }

            if (pAux1->getPosicao().x > pAux2->getPosicao().x) {
                dx = abs(pAux2->getPosicao().x - pAux1->getPosicao().x);
                intersec_x = pAux2->getTamanho().x - dx;
            }
            else {
                dcentros_x = pAux1->getTamanho().x;
                dx = abs(pAux1->getPosicao().x - pAux2->getPosicao().x);
                intersec_x = dcentros_x - dx;
            }

            if (intersec_x> 0.0 && intersec_y > 0.0) {
                pAux2->colidir(pAux1, intersec_x, intersec_y);
                pAux1->colidir(pAux2, intersec_x, intersec_y);
            }

        }
    }
 
}


/*
void GerenciadorColisoes::clear()
{
    Entidades::EntidadeMovel* pAux = NULL;
    for (int i = 0; i < listaEntidadesMoveis->getLen(); i++) {
        pAux = static_cast<Entidades::EntidadeMovel*>((*listaEntidadesMoveis).getItem(i));
        if (pAux != NULL) {
            if (pAux) {// Mudar depois
                listaEntidadesMoveis->removeEntidade(pAux);
                i--;
                if (i < 0)
                    i = -1;
            }
        }
    }
}
*/

void GerenciadorColisoes::setListaEntidades(ListaEntidades* lEM, ListaEntidades* lEE)
{
    this->listaEntidadesMoveis = lEM;
    this->listaEntidadesEstaticas = lEE;
}