#include "colisao.h"

Gerenciadores::GerenciadorColisoes* Gerenciadores::GerenciadorColisoes::instancia = NULL;

Gerenciadores::GerenciadorColisoes::GerenciadorColisoes(Listas::ListaEntidades* lEM, Listas::ListaEntidades* lEE)
{
    listaEntidadesMoveis = lEM;
    listaEntidadesEstaticas = lEE;
}

Gerenciadores::GerenciadorColisoes* Gerenciadores::GerenciadorColisoes::getInstancia(Listas::ListaEntidades* lEM, Listas::ListaEntidades* lEE)
{
    if (instancia == 0) {
        instancia = new Gerenciadores::GerenciadorColisoes(lEM, lEE);
    }
    return instancia;
}

Gerenciadores::GerenciadorColisoes::~GerenciadorColisoes()
{
    listaEntidadesMoveis = nullptr;
    listaEntidadesEstaticas = nullptr;
}

void Gerenciadores::GerenciadorColisoes::ColidirEstaticoMovel()
{
    Entidade* pAux1;
    Entidade* pAux2;
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
                colidir(pAux2, pAux1, intersec_x, intersec_y);
            }
        }
    }
}

void Gerenciadores::GerenciadorColisoes::ColidirMovelMovel(){
    //Colisão entre Entidades Moveis
    Entidade* pAux1;
    Entidade* pAux2;
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
                colidir(pAux1, pAux2, intersec_x, intersec_y);
                colidir(pAux2, pAux1, intersec_x, intersec_y);
            }

        }
    }
 
}

void Gerenciadores::GerenciadorColisoes::setListaEntidades(Listas::ListaEntidades* lEM, Listas::ListaEntidades* lEE)
{
    this->listaEntidadesMoveis = lEM;
    this->listaEntidadesEstaticas = lEE;
}


void Gerenciadores::GerenciadorColisoes::colidir(Entidade* p1, Entidade* p2, float intersec_x, float intersec_y)
{
    if (p1->getId() == 1 || p1->getId() == 2) {
        if (p2->getId() == 1 || p2->getId() == 2 || p2->getId() == 6
            || p2->getId() == 7 || p2->getId() == 8)
            resolverColisao(p1, p2, intersec_x, intersec_y);

        else if (p2->getId() == 3 || p2->getId() == 11) {
            resolverColisao(p1, p2, intersec_x, intersec_y);
            p1->setColidindo(true);
        }
        else if (p2->getId() == 5 || p2->getId() == 4) {
            resolverColisao(p1, p2, intersec_x, intersec_y);
            p2->efeito(p1);
            p1->setColidindo(true);
        }
        else if (p2->getId() == 9) {
            resolverColisao(p1, p2, intersec_x, intersec_y);
            p2->efeito(p1);
        }
    }


    else if (p1->getId() == 6) {
        if (p2->getId() == 1 || p2->getId() == 2 || p2->getId() == 3 || p2->getId() == 6
            || p2->getId() == 7 || p2->getId() == 8 || p2->getId() == 9)

            resolverColisao(p1, p2, intersec_x, intersec_y);

        else if (p2->getId() == 5 || p2->getId() == 4) {

            resolverColisao(p1, p2, intersec_x, intersec_y);
            p2->efeito(p1);
        }
    }
    else if (p1->getId() == 7) {
        if (p2->getId() == 1 || p2->getId() == 2 || p2->getId() == 3 || p2->getId() == 6
            || p2->getId() == 7 || p2->getId() == 8 || p2->getId() == 9)

            resolverColisao(p1, p2, intersec_x, intersec_y);

        else if (p2->getId() == 5 || p2->getId() == 4) {
            resolverColisao(p1, p2, intersec_x, intersec_y);
            p2->efeito(p1);
        }
    }
    else if (p1->getId() == 8) {
        if (p2->getId() == 1 || p2->getId() == 2 || p2->getId() == 3 || p2->getId() == 6
            || p2->getId() == 7 || p2->getId() == 8 || p2->getId() == 11)

            resolverColisao(p1, p2, intersec_x, intersec_y);

        else if (p2->getId() == 5 || p2->getId() == 4) {
            resolverColisao(p1, p2, intersec_x, intersec_y);
            p2->efeito(p1);
        }
    }
    else if (p1->getId() == 9) {
        if (p2->getId() == 3 || p2->getId() == 6 || p2->getId() == 5 || p2->getId() == 4 || p2->getId() == 7) {
            resolverColisao(p1, p2, intersec_x, intersec_y);
            p1->setColidindo(true);
        }
    }
}

void Gerenciadores::GerenciadorColisoes::resolverColisao(Entidade* p1, Entidade* p2, float ix, float iy)
{
    if (ix < iy)
    {
        if (p1->getPosicao().x > p2->getPosicao().x)
            p1->setPosicao(Math::CoordF(p1->getPosicao().x + ix, p1->getPosicao().y));
        else
            p1->setPosicao(Math::CoordF(p1->getPosicao().x - ix, p1->getPosicao().y));
        p1->setVelocidade(Math::CoordF(0, p1->getVelocidade().y));
    }
    else
    {
        if (p1->getPosicao().y > p2->getPosicao().y)
            p1->setPosicao(Math::CoordF(p1->getPosicao().x, p1->getPosicao().y + iy));
        else
            p1->setPosicao(Math::CoordF(p1->getPosicao().x, p1->getPosicao().y - iy));
        p1->setVelocidade(Math::CoordF(p1->getVelocidade().x, 0));
    }
}
