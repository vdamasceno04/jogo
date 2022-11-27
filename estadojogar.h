#pragma once

#include"estado.h"

//Gerenciador
#include "graphics.h"

//Fases
#include "florestaverde.h"
#include "florestavermelha.h"

//Jogador
#include "jogador.h"

//Construtor
#include "construtorestado.h"

class EstadoJogar : public Estado {
private:
    Fases::Fase* fase;
public:
    EstadoJogar(const ID ID, Fases::Fase* fase);
    ~EstadoJogar();
    void executar();
};

