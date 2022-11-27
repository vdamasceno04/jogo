#include "estado.h"


Estado::Estado(const ID ID) :
    Ente(), remover(false)
{

}

Estado::~Estado() {

}

void Estado::desenhar() {

}

void Estado::setRemover(const bool remover) {
    this->remover = remover;
}

const bool Estado::getRemover() const {
    return remover;
}


