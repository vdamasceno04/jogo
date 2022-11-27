#pragma once

#include "estadojogar.h"

#include "construtorfase.h"
#include "MenuPrincipal.h"


class ConstrutorEstado {
public:
    ConstrutorEstado();
    ~ConstrutorEstado();
    Estado* criarEstado(const ID ID);
private:
    Estado* criarEstadoJogar(const ID ID);
    Estado* criarEstadoMenuprincipal(const ID ID);
    //Estado::Estado* criarMenuEscolher();
    //Estado::Estado* criarLeaderboard();
};

