#pragma once
#include <SFML/Graphics.hpp>
#include"gerenciadorestados.h"
#include "florestaverde.h"
#include "florestavermelha.h"
#include "MenuPrincipal.h"
#include "MenuInterno.h"


using namespace Gerenciadores;

class Jogo
{
private:
  
	Graphics* pGG;
	GerenciadorColisoes* pGC;
	GerenciadorEstado* pGE;

public:
	Jogo();
	~Jogo();
	void inicializar();
	void executar();
};