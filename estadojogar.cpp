#include "estadojogar.h"

EstadoJogar::EstadoJogar(const ID ID, Fases::Fase* fase) :
    Estado(ID), fase(fase)
{

}

EstadoJogar::~EstadoJogar() {

}

/*Jogador* EstadoJogar::getJogador() {
    return fase->getJogador();
}*/

void EstadoJogar::executar() {
    fase->executar();
}