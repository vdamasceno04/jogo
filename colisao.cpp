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

void GerenciadorColisoes::Colidir()
{
    Entidades::Entidade* pAux1;
    Entidades::Entidade* pAux2;

    int i, j;

    //Colisão entre Etidades Moveis e Estaticas
    for (i = 0; i < listaEntidadesEstaticas->getLen(); i++)
    {

        for (j = 0; j < listaEntidadesMoveis->getLen(); j++)
        {
            pAux1 = listaEntidadesEstaticas->getItem(i);
            pAux2 = listaEntidadesMoveis->getItem(j);

            if (pAux2->getSprite().getPosition().y + 120.0 > pAux1->getSprite().getPosition().y
                && pAux1->getId() != fundo)
            {
                //printf("Entrou\n");
                pAux2->colidir(pAux1, pAux2->getId());
            }
           // if(pAux2->getSprite().getPosition().y + 120.0 > pAux1->getSprite().getPosition().y
          //      && pAux1->getId() == espinho)

        }
    }

    //Colisão entre Entidades Moveis
    for (i = 0; i < listaEntidadesMoveis->getLen(); i++)
    {
        for (j = 0; j < listaEntidadesMoveis->getLen(); j++)
        {
            pAux1 = listaEntidadesEstaticas->getItem(i);
            pAux2 = listaEntidadesMoveis->getItem(j);

        }
    }

    //clear();?

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