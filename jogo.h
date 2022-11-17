#pragma once
#include <SFML/Graphics.hpp>
#include "florestaverde.h"

using namespace Managers;

class Jogo
{
private:
	FlorestaVerde fase1;
	Managers::Graphics* pGG;
	GerenciadorColisoes* pGC;

public:
	Jogo();
	~Jogo();
	void inicializar();
	void executar();
};