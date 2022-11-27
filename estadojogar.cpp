#include "estadojogar.h"

EstadoJogar::EstadoJogar(const ID ID, Fases::Fase* fase) :
    Estado(ID), fase(fase)
{

}

EstadoJogar::~EstadoJogar() {

}

void EstadoJogar::executar() {
    fase->executar();
}