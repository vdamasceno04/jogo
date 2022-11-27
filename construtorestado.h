#pragma once

#include "estadojogar.h"

#include "construtorfase.h"


class ConstrutorEstado {
public:
    ConstrutorEstado();
    ~ConstrutorEstado();
    Estado* criarEstado(const ID ID);
private:
    Estado* criarEstadoJogar(const ID ID);
    //Estado::Estado* criarMenuPrinciapal();
    //Estado::Estado* criarMenuPausar();
    //Estado::Estado* criarMenuSalvar();
    //Estado::Estado* criarMenuOpcao();
    //Estado::Estado* criarColocao();
};

