#pragma once

//Fase
#include "florestaverde.h"
#include "florestavermelha.h"


class ConstrutorFase {
public:
    ConstrutorFase();
    ~ConstrutorFase();
    Fases::Fase* criarFase(const ID ID);
private:
    Fases::Fase* criarFlorestaVerde();
    Fases::Fase* criarFlorestaVermelha();
};

